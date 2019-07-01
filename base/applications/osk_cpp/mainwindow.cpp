/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * FILE:            base/applications/osk/mainwindow.cpp
 * PURPOSE:         On screen keyboard - Main window object implementation
 * PROGRAMMERS:     Denis ROBERT
 *                  Bișoc George
 * 					Baruch Rutman (C++ rewrite)
 */
#include "osk.hpp"

/* Create primary object window */
BOOL OSKWindow::Init()
{
    WNDCLASSEXW wc = { 0 };
    LOGFONTW logfont = { 0 };

    hIcon = LoadIconW(hInst, MAKEINTRESOURCEW(IDI_OSK));

    if (!LoadStringW(hInst, STRING_OSK, szCaption, MAX_PATH))
        StringCchCopyW(szCaption, MAX_PATH, L"On screen keyboard");

    if (!LoadStringW(hInst, STRING_FONT, logfont.lfFaceName, LF_FACESIZE))
        StringCchCopyW(logfont.lfFaceName, LF_FACESIZE, L"MS Shell Dlg");

    logfont.lfHeight = 16;
    hFont = CreateFontIndirectW(&logfont);

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    wc.lpszClassName = L"OSKMainWindow";
    wc.lpszMenuName = MAKEINTRESOURCEW(IDR_OSK_MENU);
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hIcon = hIcon;
    wc.hIconSm = static_cast<HICON>(CopyImage(hIcon, IMAGE_ICON, GetSystemMetrics(SM_CXSMICON),
                                    GetSystemMetrics(SM_CYSMICON), LR_COPYFROMRESOURCE));

    if (!RegisterClassExW(&wc))
        return FALSE;

    LoadSettings();

    /* Choose dimensions for the main window */
    if (bIsEnhancedKB)
    {
        szDim.cx = KB_ENHANCED_CX;
        szDim.cy = KB_NORMAL_CY;
    }
    else
    {
        szDim.cx = KB_NORMAL_CX;
        szDim.cy = KB_NORMAL_CY;
    }

    hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_NOACTIVATE | WS_EX_APPWINDOW,
                           L"OSKMainWindow", szCaption, WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN,
                           ptPos.x, ptPos.y, szDim.cx, szDim.cy, nullptr, nullptr, hInst, this);
    RevealWindow(hwnd);
    return TRUE;
}
/* The main window procedure */
LRESULT OSKWindow::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            HMONITOR hMonitor;
            MONITORINFO info;
            POINT point = {0};
            RECT rcWindow, rcIntersect;

            if (bShowWarning)
                bShowWarning = DialogBoxW(hInst, MAKEINTRESOURCEW(IDD_WARNINGDIALOG_OSK), hwnd, WarningDlgProc);

            Keyboard = new OSKKeyboard;

            if (!Keyboard)
            {
                PostQuitMessage(0);
                return FALSE;
            }
            /* First time create the keyboard window */
            hwndKeyboard = Keyboard->Init(hwnd);

            if (!hwndKeyboard)
            {
                PostQuitMessage(0);
                return FALSE;
            }
            /* Provide pointer to bSoundClick so that Keyboard object will know when to use sounds */
            Keyboard->bSoundClick = &bSoundClick;
            /* Check menu items */
            CheckMenuItem(GetMenu(hwnd), IDM_CLICK_SOUND, MF_BYCOMMAND | (bSoundClick ? MF_CHECKED : MF_UNCHECKED));
            CheckMenuItem(GetMenu(hwnd), IDM_STANDARD_KB, MF_BYCOMMAND | (!bIsEnhancedKB ? MF_CHECKED : MF_UNCHECKED));
            CheckMenuItem(GetMenu(hwnd), IDM_ENHANCED_KB, MF_BYCOMMAND | (bIsEnhancedKB ? MF_CHECKED : MF_UNCHECKED));
            /* Get screen info */
            hMonitor = MonitorFromPoint(point, MONITOR_DEFAULTTOPRIMARY);
            info.cbSize = sizeof(MONITORINFO);
            GetMonitorInfoW(hMonitor, &info);
            GetWindowRect(hwnd, &rcWindow);
            /*
                If the coordination values are default then re-initialize using the specific formulas
                to move the dialog at the bottom of the screen.

                Calculate the intersection of two rectangle sources (dialog and work desktop area).
                If such sources do not intersect, then the dialog is deemed as "off screen".

                Or there's still some intersection but we're not for sure if it is sufficient (the dialog could also be partially hidden).
                Therefore, check the remaining intersection if it's enough.
            */
            if ((ptPos.x == CW_USEDEFAULT && ptPos.y == CW_USEDEFAULT) ||
                (IntersectRect(&rcIntersect, &rcWindow, &info.rcWork) == FALSE) ||
                (rcWindow.top < info.rcWork.top || rcWindow.left < info.rcWork.left || rcWindow.right > info.rcWork.right || rcWindow.bottom > info.rcWork.bottom))
            {
                ptPos.x = (info.rcMonitor.left + info.rcMonitor.right - (rcWindow.right - rcWindow.left)) / 2;
                ptPos.y = info.rcMonitor.bottom - (rcWindow.bottom - rcWindow.top);
            }
            /* Move window according to the placement coordination */
            SetWindowPos(hwnd, HWND_TOP, ptPos.x, ptPos.y, 0, 0, SWP_NOSIZE);
            return TRUE;
        }
        case WM_PAINT:
        {
            RevealWindow(hwndKeyboard);
            return TRUE;
        }
        case WM_COMMAND:
        {
            return OnCommand(wParam, lParam);
        }
        case WM_INPUTLANGCHANGE:
        case WM_INPUTLANGCHANGEREQUEST:
        {
            /* Redraw Keyboard according to the layout switch */
            return UpdateKeyboard(UPDATE_LANG, 0);
        }
        case WM_CLOSE:
        case WM_DESTROY:
        {
            SaveSettings();
            DestroyWindow(hwnd);
            PostQuitMessage(0);
            return FALSE;
        }
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

/* WM_COMMAND handler */
LRESULT OSKWindow::OnCommand(WPARAM wParam, LPARAM lParam)
{
    switch (LOWORD(wParam))
    {
        case IDM_EXIT:
        {
            /* Send WM_CLOSE message to close cleanly */
            SendMessageW(hwnd, WM_CLOSE, 0, 0);
            return FALSE;
        }
        case IDM_ENHANCED_KB:
        case IDM_STANDARD_KB:
        {   
            /* Check and resize window accordingly */
            return UpdateKeyboard(UPDATE_LAYOUT , LOWORD(wParam));
        }
        case IDM_CLICK_SOUND:
        {
            bSoundClick = !bSoundClick;
            CheckMenuItem(GetMenu(hwnd), IDM_CLICK_SOUND, MF_BYCOMMAND | (bSoundClick ? MF_CHECKED : MF_UNCHECKED));
            return TRUE;
        }
        case IDM_ABOUT:
        {
            WCHAR szAuthors[MAX_PATH];

            LoadStringW(hInst, STRING_AUTHORS, szAuthors, MAX_PATH);
            ShellAboutW(hwnd, szCaption, szAuthors, hIcon);
            return TRUE;
        }
        default:
        {
            return FALSE;
        }
    }
}

/* Update window size/keyboard layout */
LRESULT OSKWindow::UpdateKeyboard(INT iReason, WORD wParam)
{
    if (iReason == UPDATE_LAYOUT)
    {
        if ((wParam == IDM_ENHANCED_KB && bIsEnhancedKB) ||
            (wParam == IDM_STANDARD_KB && !bIsEnhancedKB))
        {
            /* No resize is required */
            return TRUE;
        }

        /* Switch layout info */
        bIsEnhancedKB = !bIsEnhancedKB;
        CheckMenuItem(GetMenu(hwnd), IDM_STANDARD_KB, MF_BYCOMMAND | (!bIsEnhancedKB ? MF_CHECKED : MF_UNCHECKED));
        CheckMenuItem(GetMenu(hwnd), IDM_ENHANCED_KB, MF_BYCOMMAND | (bIsEnhancedKB ? MF_CHECKED : MF_UNCHECKED));

        if (bIsEnhancedKB)
        {
            szDim.cx = KB_ENHANCED_CX;
            szDim.cy = KB_NORMAL_CY;
        }
        else
        {
            szDim.cx = KB_NORMAL_CX;
            szDim.cy = KB_NORMAL_CY;
        }
    }
    /* Resize Window */
    SetWindowPos(hwnd, HWND_TOP, 0, 0, szDim.cx, szDim.cy, SWP_NOMOVE);
    /* Update buttons if keyboard layout is updated */
    if (iReason == UPDATE_LANG)
        Keyboard->InitKeys(TRUE);
    /* Redraw keyboard window */
    RevealWindow(hwndKeyboard);
    return TRUE;
}

VOID OSKWindow::LoadSettings()
{
    HKEY hKey;
    LSTATUS lResult;

    lResult = RegOpenKeyExW(HKEY_CURRENT_USER,
                            L"Software\\Microsoft\\Osk",
                            0,
                            KEY_READ,
                            &hKey);

    if (lResult != ERROR_SUCCESS)
        return;

    ptPos.x       = QueryValue(hKey, L"WindowLeft", RET_INT, CW_USEDEFAULT);
    ptPos.y       = QueryValue(hKey, L"WindowTop", RET_INT, CW_USEDEFAULT);
    bShowWarning  = QueryValue(hKey, L"ShowWarning", RET_BOOL, TRUE);
    bIsEnhancedKB = QueryValue(hKey, L"IsEnhancedKeyboard", RET_BOOL, TRUE);
    bSoundClick   = QueryValue(hKey, L"ClickSound", RET_BOOL, FALSE);

    RegCloseKey(hKey);
}

INT OSKWindow::QueryValue(HKEY hKey, LPCWSTR lpszValue, INT ret_type, INT iDefault)
{
    DWORD dwResult;
    DWORD cbData = sizeof(DWORD);

    if (RegQueryValueExW(hKey, lpszValue, 0, 0, reinterpret_cast<LPBYTE>(&dwResult), &cbData) != ERROR_SUCCESS)
        return iDefault;

    if (ret_type == RET_BOOL)
        return (dwResult != 0);
    else
        return dwResult;
}

VOID OSKWindow::SaveSettings()
{
    HKEY hKey;
    LSTATUS lResult;
    WINDOWPLACEMENT wp;

    lResult = RegCreateKeyExW(HKEY_CURRENT_USER,
                              L"Software\\Microsoft\\Osk",
                              0,
                              nullptr,
                              0,
                              KEY_WRITE,
                              nullptr,
                              &hKey,
                              nullptr);

    if (lResult != ERROR_SUCCESS)
        return;

    wp.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(hwnd, &wp);

    SaveValue(hKey, L"WindowLeft", wp.rcNormalPosition.left);
    SaveValue(hKey, L"WindowTop", wp.rcNormalPosition.top);
    SaveValue(hKey, L"ShowWarning", bShowWarning);
    SaveValue(hKey, L"IsEnhancedKeyboard", bIsEnhancedKB);
    SaveValue(hKey, L"ClickSound", bSoundClick);

    RegCloseKey(hKey);
}

VOID OSKWindow::SaveValue(HKEY hKey, LPCWSTR lpszValue, INT iValue)
{
    RegSetValueExW(hKey, lpszValue, 0, REG_DWORD, reinterpret_cast<LPBYTE>(&iValue), sizeof(INT));
}
/* Warning dialog procedure */
INT_PTR CALLBACK OSKWindow::WarningDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
            return TRUE;

        case WM_COMMAND:
        {
            if (LOWORD(wParam) == IDOK)
            {
                EndDialog(hDlg, !IsDlgButtonChecked(hDlg, IDC_SHOWWARNINGCHECK));
                return TRUE;
            }
        }
        default:
            return FALSE;
    }
}
/* Cleanup: Delete the allocated OSKKeyboard object, unregister classes, and delete hFont */
VOID OSKWindow::Cleanup()
{
    delete Keyboard;
    UnregisterClassW(L"OSKMainWindow", hInst);
    UnregisterClassW(L"OSKKeyboard", hInst);
    if (hFont)
        DeleteObject(hFont);
}
