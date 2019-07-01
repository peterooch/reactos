/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * PURPOSE:         On-screen keyboard.
 * COPYRIGHT:       Denis ROBERT
 *                  Copyright 2019 Bișoc George (fraizeraust99 at gmail dot com)
 */

/* INCLUDES *******************************************************************/

#include "precomp.h"

//(re)move me
#define STRING_FONT 0
#define KB_NORMAL_CX 570
#define KB_ENHANCED_CX 700
#define KB_NORMAL_CY 250
/* GLOBALS ********************************************************************/

OSK_GLOBALS Globals;

OSK_KEYLEDINDICATOR LedKey[] =
{
    {VK_NUMLOCK, IDC_LED_NUM, 0x0145, FALSE},
    {VK_CAPITAL, IDC_LED_CAPS, 0x013A, FALSE},
    {VK_SCROLL, IDC_LED_SCROLL, 0x0146, FALSE}
};

/* FUNCTIONS ******************************************************************/

BOOL OSK_CreateWindow()
{
    HWND hwnd;
    WNDCLASSEXW wc = { 0 };

    Globals.hIcon = LoadIconW(Globals.hInstance, MAKEINTRESOURCEW(IDI_OSK));

    if (!LoadStringW(Globals.hInstance, STRING_OSK, Globals.szCaption, MAX_PATH))
        StringCchCopyW(Globals.szCaption, MAX_PATH, L"On screen keyboard");

    wc.lpfnWndProc   = OSK_WndProc;
    wc.hInstance     = Globals.hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"OSKMainWindow";
    wc.lpszMenuName  = MAKEINTRESOURCEW(IDR_OSK_MENU);
    wc.cbSize        = sizeof(WNDCLASSEXW);
    wc.hIcon         = Globals.hIcon;
    wc.hIconSm       = (HICON)CopyImage(Globals.hIcon, IMAGE_ICON, GetSystemMetrics(SM_CXSMICON),
                                        GetSystemMetrics(SM_CYSMICON), LR_COPYFROMRESOURCE);
    if (!RegisterClassExW(&wc))
        return FALSE;

    /* Load the settings from the registry hive */
    LoadDataFromRegistry();

    /* Choose dimensions for the main window */
    if (Globals.bIsEnhancedKeyboard)
    {
        Globals.DimX = KB_ENHANCED_CX;
        Globals.DimY = KB_NORMAL_CY;
    }
    else
    {
        Globals.DimX = KB_NORMAL_CX;
        Globals.DimY = KB_NORMAL_CY;
    }

    hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_NOACTIVATE | WS_EX_APPWINDOW,
                           L"OSKMainWindow",
                           Globals.szCaption,
                           WS_SYSMENU | WS_MINIMIZEBOX,
                           Globals.PosX,
                           Globals.PosY,
                           Globals.DimX,
                           Globals.DimY,
                           NULL,
                           NULL,
                           Globals.hInstance,
                           NULL);
    if (!hwnd)
        return FALSE;

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    return TRUE;
}

/***********************************************************************
 *
 *          OSK_WarningProc
 *
 *  Function handler for the warning dialog box on startup
 */
INT_PTR CALLBACK OSK_WarningProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (Msg)
    {
        case WM_INITDIALOG:
        {
            return TRUE;
        }

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_SHOWWARNINGCHECK:
                {
                    Globals.bShowWarning = !IsDlgButtonChecked(hDlg, IDC_SHOWWARNINGCHECK);
                    return TRUE;
                }

                case IDOK:
                {
                    EndDialog(hDlg, LOWORD(wParam));
                    return TRUE;
                }
            }
            break;
        }
    }

    return FALSE;
}

/***********************************************************************
 *
 *          OSK_About
 *
 *  Initializes the "About" dialog box
 */
VOID OSK_About(HWND hwnd)
{
    WCHAR szTitle[MAX_BUFF];
    WCHAR szAuthors[MAX_BUFF];
    HICON OSKIcon;

    /* Load the icon */
    OSKIcon = LoadImageW(Globals.hInstance, MAKEINTRESOURCEW(IDI_OSK), IMAGE_ICON, 0, 0, LR_DEFAULTSIZE);

    /* Load the strings into the "About" dialog */
    LoadStringW(Globals.hInstance, STRING_OSK, szTitle, countof(szTitle));
    LoadStringW(Globals.hInstance, STRING_AUTHORS, szAuthors, countof(szAuthors));

    /* Finally, execute the "About" dialog by using the Shell routine */
    ShellAboutW(hwnd, szTitle, szAuthors, OSKIcon);

    /* Once done, destroy the icon */
    DestroyIcon(OSKIcon);
}

/***********************************************************************
 *
 *           OSK_Create
 *
 *  Handling of WM_CREATE
 */
LRESULT OSK_Create(HWND hwnd)
{
    HMONITOR monitor;
    MONITORINFO info;
    POINT Pt;
    RECT rcWindow, rcIntersect;

    /* If the member of the struct (bShowWarning) is set then display the dialog box */
    if (Globals.bShowWarning)
    {
        DialogBoxW(Globals.hInstance, MAKEINTRESOURCEW(IDD_WARNINGDIALOG_OSK), hwnd, OSK_WarningProc);
    }

    /* Check the checked menu item before displaying the modal box */
    if (Globals.bIsEnhancedKeyboard)
    {
        /* Enhanced keyboard dialog chosen, set the respective menu item as checked */
        CheckMenuItem(GetMenu(hwnd), IDM_ENHANCED_KB, MF_BYCOMMAND | MF_CHECKED);
        CheckMenuItem(GetMenu(hwnd), IDM_STANDARD_KB, MF_BYCOMMAND | MF_UNCHECKED);
    }
    else
    {
        /* Standard keyboard dialog chosen, set the respective menu item as checked */
        CheckMenuItem(GetMenu(hwnd), IDM_STANDARD_KB, MF_BYCOMMAND | MF_CHECKED);
        CheckMenuItem(GetMenu(hwnd), IDM_ENHANCED_KB, MF_BYCOMMAND | MF_UNCHECKED);
    }

    /* Check if the "Click Sound" option was chosen before (and if so, then tick the menu item) */
    if (Globals.bSoundClick)
    {
        CheckMenuItem(GetMenu(hwnd), IDM_CLICK_SOUND, MF_BYCOMMAND | MF_CHECKED);
    }

    /* Get screen info */
    memset(&Pt, 0, sizeof(Pt));
    monitor = MonitorFromPoint(Pt, MONITOR_DEFAULTTOPRIMARY);
    info.cbSize = sizeof(info);
    GetMonitorInfoW(monitor, &info);
    GetWindowRect(hwnd, &rcWindow);

    /*
        If the coordination values are default then re-initialize using the specific formulas
        to move the dialog at the bottom of the screen.
    */
    if (Globals.PosX == CW_USEDEFAULT && Globals.PosY == CW_USEDEFAULT)
    {
        Globals.PosX = (info.rcMonitor.left + info.rcMonitor.right - (rcWindow.right - rcWindow.left)) / 2;
        Globals.PosY = info.rcMonitor.bottom - (rcWindow.bottom - rcWindow.top);
    }

    /*
        Calculate the intersection of two rectangle sources (dialog and work desktop area).
        If such sources do not intersect, then the dialog is deemed as "off screen".
    */
    if (IntersectRect(&rcIntersect, &rcWindow, &info.rcWork) == 0)
    {
        Globals.PosX = (info.rcMonitor.left + info.rcMonitor.right - (rcWindow.right - rcWindow.left)) / 2;
        Globals.PosY = info.rcMonitor.bottom - (rcWindow.bottom - rcWindow.top);
    }
    else
    {
        /*
            There's still some intersection but we're not for sure if it is sufficient (the dialog could also be partially hidden).
            Therefore, check the remaining intersection if it's enough.
        */
        if (rcWindow.top < info.rcWork.top || rcWindow.left < info.rcWork.left || rcWindow.right > info.rcWork.right || rcWindow.bottom > info.rcWork.bottom)
        {
            Globals.PosX = (info.rcMonitor.left + info.rcMonitor.right - (rcWindow.right - rcWindow.left)) / 2;
            Globals.PosY = info.rcMonitor.bottom - (rcWindow.bottom - rcWindow.top);
        }
    }
    /* Create keyboard child window */
    if (!OSK_KeyboardCreate(hwnd))
        return -1;

    /*
        Place the window (with respective placement coordinates) as topmost, above
        every window which are not on top or are at the bottom of the Z order.
    */
    if (Globals.bAlwaysOnTop)
    {
        CheckMenuItem(GetMenu(hDlg), IDM_ON_TOP, MF_BYCOMMAND | MF_CHECKED);
        SetWindowPos(hDlg, HWND_TOPMOST, Globals.PosX, Globals.PosY, 0, 0, SWP_NOSIZE);
    }
    else
    {
        CheckMenuItem(GetMenu(hDlg), IDM_ON_TOP, MF_BYCOMMAND | MF_UNCHECKED);
        SetWindowPos(hDlg, HWND_NOTOPMOST, Globals.PosX, Globals.PosY, 0, 0, SWP_NOSIZE);
    }

    /* Set icon on visual buttons */
    OSK_SetImage(SCAN_CODE_15, IDI_BACK);
    OSK_SetImage(SCAN_CODE_16, IDI_TAB);
    OSK_SetImage(SCAN_CODE_30, IDI_CAPS_LOCK);
    OSK_SetImage(SCAN_CODE_43, IDI_RETURN);
    OSK_SetImage(SCAN_CODE_44, IDI_SHIFT);
    OSK_SetImage(SCAN_CODE_57, IDI_SHIFT);
    OSK_SetImage(SCAN_CODE_127, IDI_REACTOS);
    OSK_SetImage(SCAN_CODE_128, IDI_REACTOS);
    OSK_SetImage(SCAN_CODE_129, IDI_MENU);
    OSK_SetImage(SCAN_CODE_80, IDI_HOME);
    OSK_SetImage(SCAN_CODE_85, IDI_PG_UP);
    OSK_SetImage(SCAN_CODE_86, IDI_PG_DOWN);
    OSK_SetImage(SCAN_CODE_79, IDI_LEFT);
    OSK_SetImage(SCAN_CODE_83, IDI_TOP);
    OSK_SetImage(SCAN_CODE_84, IDI_BOTTOM);
    OSK_SetImage(SCAN_CODE_89, IDI_RIGHT);

    /* Create a green brush for leds */
    Globals.hBrushGreenLed = CreateSolidBrush(RGB(0, 255, 0));

    /* Set a timer for periodics tasks */
    Globals.iTimer = SetTimer(hDlg, 0, 50, NULL);

    return TRUE;
}

/***********************************************************************
 *
 *           OSK_Close
 *
 *  Handling of WM_CLOSE
 */
int OSK_Close(HWND hwnd)
{
    KillTimer(hwnd, Globals.iTimer);

    /* Save the settings to the registry hive */
    SaveDataToRegistry(hwnd);

    DestroyWindow(hwnd);

    /* delete GDI objects */
    if (Globals.hBrushGreenLed)
        DeleteObject(Globals.hBrushGreenLed);
    if (Globals.hFont)
        DeleteObject(Globals.hFont);

    PostQuitMessage(0);
    return TRUE;
}

/***********************************************************************
 *
 *           OSK_RefreshLEDKeys
 *
 *  Updates (invalidates) the LED icon resources then the respective
 *  keys (Caps Lock, Scroll Lock or Num Lock) are being held down
 */
VOID OSK_RefreshLEDKeys(VOID)
{
    INT i;
    BOOL bKeyIsPressed;

    for (i = 0; i < _countof(LedKey); i++)
    {
        bKeyIsPressed = (GetAsyncKeyState(LedKey[i].vKey) & 0x8000) != 0;
        if (LedKey[i].bWasKeyPressed != bKeyIsPressed)
        {
            LedKey[i].bWasKeyPressed = bKeyIsPressed;
            InvalidateRect(GetDlgItem(Globals.hMainWnd, LedKey[i].DlgResource), NULL, FALSE);
        }
    }
}

/***********************************************************************
 *
 *           OSK_DlgTimer
 *
 *  Handling of WM_TIMER
 */
int OSK_Timer(HWND hwnd)
{
    /* FIXME: To be deleted when ReactOS will support WS_EX_NOACTIVATE */
    HWND hWndActiveWindow;

    hWndActiveWindow = GetForegroundWindow();
    if (hWndActiveWindow != NULL && hWndActiveWindow != hwnd)
    {
        Globals.hActiveWnd = hWndActiveWindow;
    }

    /*
        Update the LED key indicators accordingly to their state (if one
        of the specific keys is held down).
    */
    OSK_RefreshLEDKeys();

    return TRUE;
}

/***********************************************************************
 *
 *           OSK_Command
 *
 *  All handling of commands
 */
BOOL OSK_Command(WPARAM wCommand, HWND hWndControl)
{
    WORD ScanCode;
    INPUT Input;
    BOOL bExtendedKey;
    BOOL bKeyDown;
    BOOL bKeyUp;
    LONG WindowStyle;
    INT i;

    /* FIXME: To be deleted when ReactOS will support WS_EX_NOACTIVATE */
    if (Globals.hActiveWnd)
    {
        MSG msg;

        SetForegroundWindow(Globals.hActiveWnd);
        while (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    /* KeyDown and/or KeyUp ? */
    if ((GetWindowLongPtrW(hWndControl, GWL_STYLE) & BS_AUTOCHECKBOX) == BS_AUTOCHECKBOX)
    {
        /* 2-states key like Shift, Alt, Ctrl, ... */
        if (SendMessageW(hWndControl, BM_GETCHECK, 0, 0) == BST_CHECKED)
        {
            bKeyDown = TRUE;
            bKeyUp = FALSE;
        }
        else
        {
            bKeyDown = FALSE;
            bKeyUp = TRUE;
        }
    }
    else
    {
        /* Other key */
        bKeyDown = TRUE;
        bKeyUp = TRUE;
    }

    /* Get the key from dialog control key command */
    ScanCode = wCommand;

    /*
        The user could've pushed one of the key buttons of the dialog that
        can trigger particular function toggling (Caps Lock, Num Lock or Scroll Lock). Update
        (invalidate) the LED icon resources accordingly.
    */
    for (i = 0; i < _countof(LedKey); i++)
    {
        if (LedKey[i].wScanCode == ScanCode)
        {
            InvalidateRect(GetDlgItem(Globals.hMainWnd, LedKey[i].DlgResource), NULL, FALSE);
        }
    }

    /* Extended key ? */
    if (ScanCode & 0x0200)
        bExtendedKey = TRUE;
    else
        bExtendedKey = FALSE;
    ScanCode &= 0xFF;

    /* Press and release the key */
    if (bKeyDown)
    {
        Input.type = INPUT_KEYBOARD;
        Input.ki.wVk = 0;
        Input.ki.wScan = ScanCode;
        Input.ki.time = GetTickCount();
        Input.ki.dwExtraInfo = GetMessageExtraInfo();
        Input.ki.dwFlags = KEYEVENTF_SCANCODE;
        if (bExtendedKey) Input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        SendInput(1, &Input, sizeof(Input));
    }

    if (bKeyUp)
    {
        Input.type = INPUT_KEYBOARD;
        Input.ki.wVk = 0;
        Input.ki.wScan = ScanCode;
        Input.ki.time = GetTickCount();
        Input.ki.dwExtraInfo = GetMessageExtraInfo();
        Input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        if (bExtendedKey) Input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        SendInput(1, &Input, sizeof(Input));
    }

    /* Play the sound during clicking event (only if "Use Click Sound" menu option is ticked) */
    if (Globals.bSoundClick)
    {
        PlaySoundW(MAKEINTRESOURCEW(IDI_SOUNDCLICK), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
    }

    return TRUE;
}

/***********************************************************************
 *
 *           OSK_ReleaseKey
 *
 *  Release the key of ID wCommand
 */
BOOL OSK_ReleaseKey(HWND hwnd, WORD ScanCode)
{
    INPUT Input;
    BOOL bExtendedKey;
    HWND hWndControl;

    hWndControl = GetDlgItem(hwnd, ScanCode);

    /* Is it a 2-states key ? */
    if ((GetWindowLongPtrW(hWndControl, GWL_STYLE) & BS_AUTOCHECKBOX) != BS_AUTOCHECKBOX) return FALSE;

    /* Is the key down ? */
    if (SendMessageW(hWndControl, BM_GETCHECK, 0, 0) != BST_CHECKED) return TRUE;

    /* Extended key ? */
    if (ScanCode & 0x0200)
        bExtendedKey = TRUE;
    else
        bExtendedKey = FALSE;
    ScanCode &= 0xFF;

    /* Release the key */
    Input.type = INPUT_KEYBOARD;
    Input.ki.wVk = 0;
    Input.ki.wScan = ScanCode;
    Input.ki.time = GetTickCount();
    Input.ki.dwExtraInfo = GetMessageExtraInfo();
    Input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    if (bExtendedKey) Input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
    SendInput(1, &Input, sizeof(Input));

    return TRUE;
}

/***********************************************************************
 *
 *       OSK_WndProc
 */
LRESULT APIENTRY OSK_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            return OSK_Create(hwnd);
        }
        case WM_PAINT:
        {
            ShowWindow(Globals.hKeyboardWnd, SW_SHOW);
            UpdateWindow(Globals.hKeyboardWnd);
            return TRUE;
        }
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDM_EXIT:
                {
                    /* Quickly post a WM_CLOSE message */
                    return PostMessageW(hwnd, WM_CLOSE, 0, 0);
                }
                case IDM_ENHANCED_KB:
                case IDM_STANDARD_KB:
                {
                    if ((LOWORD(wParam) == IDM_ENHANCED_KB && Globals.bIsEnhancedKeyboard) ||
                        (LOWORD(wParam) == IDM_STANDARD_KB && !Globals.bIsEnhancedKeyboard))
                    {
                        /*
                            The user attempted to switch to enhanced keyboard dialog type.
                            Set the member value as TRUE, destroy the dialog and save the data configuration into the registry.
                        */
                        Globals.bIsEnhancedKeyboard = TRUE;
                        EndDialog(hDlg, FALSE);
                        SaveSettings();

                        /* Change the condition of enhanced keyboard item menu to checked */
                        CheckMenuItem(GetMenu(hDlg), IDM_ENHANCED_KB, MF_BYCOMMAND | MF_CHECKED);
                        CheckMenuItem(GetMenu(hDlg), IDM_STANDARD_KB, MF_BYCOMMAND | MF_UNCHECKED);

                        /*
                            Before creating the dialog box restore the coordinates. The user can
                            move the dialog around before choosing a different dialog layout therefore
                            we must create the dialog with the new coordinates.
                        */
                        OSK_RestoreDlgPlacement(hDlg);

                        /* Finally, display the dialog modal box with the enhanced keyboard dialog */
                        DialogBoxW(Globals.hInstance,
                                   MAKEINTRESOURCEW(MAIN_DIALOG_ENHANCED_KB),
                                   GetDesktopWindow(),
                                   OSK_DlgProc);
                    }

                    /* Switch layout info */
                    Globals.bIsEnhancedKeyboard = !Globals.bIsEnhancedKeyboard;
                    CheckMenuItem(GetMenu(hwnd), IDM_STANDARD_KB, MF_BYCOMMAND | (!Globals.bIsEnhancedKeyboard ? MF_CHECKED : MF_UNCHECKED));
                    CheckMenuItem(GetMenu(hwnd), IDM_ENHANCED_KB, MF_BYCOMMAND | (Globals.bIsEnhancedKeyboard ? MF_CHECKED : MF_UNCHECKED));

                    if (Globals.bIsEnhancedKeyboard)
                    {
                        Globals.DimX = KB_ENHANCED_CX;
                        Globals.DimY = KB_NORMAL_CY;
                    }
                    else
                    {
                        Globals.DimX = KB_NORMAL_CX;
                        Globals.DimY = KB_NORMAL_CY;
                    }
                    /* Resize Window */
                    SetWindowPos(hwnd, HWND_TOP, 0, 0, Globals.DimX, Globals.DimY, SWP_NOMOVE);
                    InvalidateRect(hwnd, NULL, FALSE);
                    return TRUE;
                }
                case IDM_CLICK_SOUND:
                {
                    /*
                        This case is triggered when the user attempts to click on the menu item. Before doing anything,
                        we must check the condition state of such menu item so that we can tick/untick the menu item accordingly.
                    */
                    if (!Globals.bSoundClick)
                    {
                        Globals.bSoundClick = TRUE;
                        CheckMenuItem(GetMenu(hwnd), IDM_CLICK_SOUND, MF_BYCOMMAND | MF_CHECKED);
                    }
                    else
                    {
                        Globals.bSoundClick = FALSE;
                        CheckMenuItem(GetMenu(hwnd), IDM_CLICK_SOUND, MF_BYCOMMAND | MF_UNCHECKED);
                    }
                    return TRUE;
                }
                case IDM_ABOUT:
                {
                    OSK_About(hwnd);
                    return TRUE;
                }
            }
            break;
        }
        case WM_TIMER:
        {
            return OSK_Timer(hwnd);
        }
        case WM_CLOSE:
        {
            return OSK_Close(hwnd);
        }
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

/***********************************************************************
 *
 *       WinMain
 */
int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE prev,
                    LPWSTR cmdline,
                    int show)
{
    HANDLE hMutex;
    DWORD dwError;
    INITCOMMONCONTROLSEX iccex;
    MSG msg;

    UNREFERENCED_PARAMETER(prev);
    UNREFERENCED_PARAMETER(cmdline);
    UNREFERENCED_PARAMETER(show);

    /*
        Obtain a mutex for the program. This will ensure that
        the program is launched only once.
    */
    hMutex = CreateMutexW(NULL, FALSE, L"OSKRunning");

    /* Check if there's already a mutex for the program */
    if (hMutex)
    {
        dwError = GetLastError();
        if (dwError == ERROR_ALREADY_EXISTS)
        {
            /*
            A mutex with the object name has been created previously.
            Therefore, another instance is already running.
            */
            DPRINT("wWinMain(): Failed to create a mutex! The program instance is already running.\n");
            CloseHandle(hMutex);
            return 0;
        }
    }

    /* Load the common controls */
    iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    iccex.dwICC = ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES;
    InitCommonControlsEx(&iccex);

    ZeroMemory(&Globals, sizeof(Globals));
    Globals.hInstance = hInstance;

    if (OSK_CreateWindow())
    {   
        while (GetMessageW(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }       
        UnregisterClassW(L"OSKMainWindow", Globals.hInstance);
        UnregisterClassW(L"OSKKeyboard", Globals.hInstance);
    }

    /* Delete the mutex */
    if (hMutex)
    {
        CloseHandle(hMutex);
    }

    return 0;
}

/* EOF */
