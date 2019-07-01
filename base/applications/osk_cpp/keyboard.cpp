/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * FILE:            base/applications/osk/keyboard.cpp
 * PURPOSE:         On screen keyboard - Keyboard object implementation
 * PROGRAMMERS:     Denis ROBERT
 * 					Bișoc George
 * 					Baruch Rutman (C++ rewrite)
 */

#include "osk.hpp"
#include "keydata.h"

/* Create primary object window and pass handle to caller */
HWND OSKKeyboard::Init(HWND hWndParent)
{
    WNDCLASSEXW wc = { 0 };

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    wc.lpszClassName = L"OSKKeyboard";
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassExW(&wc))
            return nullptr;

	/* Create primary keyboard window, at max possible size */
    hwnd = CreateWindowW(L"OSKKeyboard", L"",
                         WS_CHILD | WS_CLIPCHILDREN,
                         0, 0, KB_ENHANCED_CX, KB_NORMAL_CY,
                         hWndParent, nullptr, hInst, this);

    return hwnd;
}

/* The Keyboards window procedure */
LRESULT OSKKeyboard::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            /* Allocate space to store the button handles */
            hUniqueKeys = new HWND[nUniqueKeys];
            hKeys = new HWND[nKeys];

            if (!hKeys || !hUniqueKeys || !InitKeys(FALSE))
            {
                PostQuitMessage(0);
                return FALSE;
            }
            /* Create LED brushes */
            hBrushGreenLed = CreateSolidBrush(RGB(0, 255, 0));
            hBrushStatic = CreateSolidBrush(RGB(255, 255, 255));
            timer = SetTimer(hwnd, 0, 200, nullptr);
            return TRUE;
        }
        case WM_PAINT:
        {
            UINT i;
			/* Show all the buttons */
            for (i = 0; i < nUniqueKeys; i++)
                RevealWindow(hUniqueKeys[i]);

            for (i = 0; i < nKeys; i++)
                RevealWindow(hKeys[i]);

			/* Show LEDs */
            RevealWindow(hCapsLock);
            RevealWindow(hNumLock);
            RevealWindow(hScrollLock);
            RevealWindow(hCapsText);
            RevealWindow(hNumText);
            RevealWindow(hScrollText);
            return TRUE;
        }
        case WM_CTLCOLORSTATIC:
        {
            HWND hCtrl = (HWND)lParam;

            if (hCtrl == hNumLock)
            {
                if (GetKeyState(VK_NUMLOCK) & 0x0001)
                    return (LRESULT)hBrushGreenLed;
                else
                    return (LRESULT)GetStockObject(BLACK_BRUSH);
            }
            if (hCtrl == hCapsLock)
            {
                if (GetKeyState(VK_CAPITAL) & 0x0001)
                    return (LRESULT)hBrushGreenLed;
                else
                    return (LRESULT)GetStockObject(BLACK_BRUSH);
            }
            if (hCtrl == hScrollLock)
            {
                if (GetKeyState(VK_SCROLL) & 0x0001)
                    return (LRESULT)hBrushGreenLed;
                else
                    return (LRESULT)GetStockObject(BLACK_BRUSH);
            }
            if (hCtrl == hScrollText || hCtrl == hCapsText || hCtrl == hNumText)
            {
                return (LRESULT)hBrushStatic;
            }
            break;
        }
        case WM_TIMER:
        {
			HWND hActive = GetForegroundWindow();

			if (hActive && hActive != GetParent(hwnd))
				hActiveWindow = hActive;

            InvalidateRect(hwnd, NULL, TRUE);
            return TRUE;
        }
        case WM_COMMAND:
        {
            return OnCommand(wParam, lParam);
        }
        case WM_CLOSE:
        case WM_DESTROY:
        {
            UINT i;
            KillTimer(hwnd, timer);

            ReleaseKey(SCAN_CODE_44); // Left shift
            ReleaseKey(SCAN_CODE_57); // Right shift
            ReleaseKey(SCAN_CODE_58); // Left ctrl
            ReleaseKey(SCAN_CODE_60); // Left alt
            ReleaseKey(SCAN_CODE_62); // Right alt
            ReleaseKey(SCAN_CODE_64); // Right ctrl

            /* Destroy key buttons */
            for (i = 0; i < nUniqueKeys; i++)
                DestroyWindow(hUniqueKeys[i]);

            for (i = 0; i < nKeys; i++)
                DestroyWindow(hKeys[i]);

            /* Destroy LEDs */
            DestroyWindow(hCapsLock);
            DestroyWindow(hNumLock);
            DestroyWindow(hScrollLock);
            DestroyWindow(hCapsText);
            DestroyWindow(hNumText);
            DestroyWindow(hScrollText);

            /* Delete brushes */
            DeleteObject(hBrushGreenLed);
            DeleteObject(hBrushStatic);
            return TRUE;
        }
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

/* Issues keyboard commands according to parameters received */
LRESULT OSKKeyboard::OnCommand(WPARAM wParam, LPARAM lParam)
{
    WORD ScanCode;
    INPUT Input;
    BOOL bExtendedKey;
    BOOL bKeyDown;
    BOOL bKeyUp;
    HWND hCtrl = (HWND)lParam;

    if (hActiveWindow)
    {
        MSG msg;

        SetForegroundWindow(hActiveWindow);
        while (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    /* KeyDown and/or KeyUp ? */
    if ((GetWindowLongPtrW(hCtrl, GWL_STYLE) & BS_AUTOCHECKBOX) == BS_AUTOCHECKBOX)
    {
        /* 2-states key like Shift, Alt, Ctrl, ... */
        if (SendMessageW(hCtrl, BM_GETCHECK, 0, 0) == BST_CHECKED)
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

    /* Extended key ? */
    ScanCode = static_cast<WORD>(wParam);
    if (ScanCode & 0x0200)
        bExtendedKey = TRUE;
    else
        bExtendedKey = FALSE;
    ScanCode &= 0xFF;

    /* Press and release the key */
    Input.type = INPUT_KEYBOARD;
    Input.ki.wVk = 0;
    Input.ki.wScan = ScanCode;
    Input.ki.time = GetTickCount();
    Input.ki.dwExtraInfo = GetMessageExtraInfo();
    if (bKeyDown)
    {
        Input.ki.dwFlags = KEYEVENTF_SCANCODE;
        if (bExtendedKey) Input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        SendInput(1, &Input, sizeof(Input));
    }
    if (bKeyUp)
    {
        Input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        if (bExtendedKey) Input.ki.dwFlags |= KEYEVENTF_EXTENDEDKEY;
        SendInput(1, &Input, sizeof(Input));
    }

    /* Play the sound during clicking event (only if "Use Click Sound" menu option is ticked) */
    if (*bSoundClick)
        PlaySoundW(MAKEINTRESOURCEW(IDI_SOUNDCLICK), hInst, SND_RESOURCE | SND_ASYNC);

    return TRUE;
}

/* Create or Refresh the keyboard buttons, pulling from the keydata header
 * the required information for each button.
 */
BOOL OSKKeyboard::InitKeys(BOOL bRefresh)
{
    HICON hIcon;
    LPCWSTR szKey;
    WCHAR wKey[2] = { 0 };
    UINT i, uVirtKey;
    BYTE lpKeyStates[256];

    if (!bRefresh)
    {
	    /* Handle unique keys. modifier keys, start key, and others */
        for (i = 0; i < nUniqueKeys; i++)
        {
                hUniqueKeys[i] = CreateWindowW(L"button", UniqueKeys[i].lpText,
                                             WS_CHILD | UniqueKeys[i].uFlags,
                                             UniqueKeys[i].x, UniqueKeys[i].y,
                                             UniqueKeys[i].cx, UniqueKeys[i].cy,
                                             hwnd, (HMENU)UniqueKeys[i].uID, hInst, nullptr);

                if (!hUniqueKeys)
                    return FALSE;
            if (UniqueKeys[i].uResource != 0)
            {
                hIcon = (HICON)LoadImageW(hInst, MAKEINTRESOURCEW(UniqueKeys[i].uResource),
                                          IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);

                if (hIcon)
                    SendMessageW(hUniqueKeys[i], BM_SETIMAGE, IMAGE_ICON, reinterpret_cast<LPARAM>(hIcon));
            }
        }
        /* Create LED indicators */
        hNumText    = CreateWindowW(L"static", L"Num", WS_CHILD, 575, 5, 40, 20, hwnd, (HMENU)IDC_STATIC, hInst, nullptr);
        hCapsText   = CreateWindowW(L"static", L"Caps", WS_CHILD, 615, 5, 40, 20, hwnd, (HMENU)IDC_STATIC, hInst, nullptr);
        hScrollText = CreateWindowW(L"static", L"Scroll", WS_CHILD, 655, 5, 40, 20, hwnd, (HMENU)IDC_STATIC, hInst, nullptr);
        hNumLock    = CreateWindowW(L"static", L"", WS_CHILD | SS_CENTER | SS_NOTIFY, 585, 25, 7, 5, hwnd, (HMENU)IDC_LED_NUM, hInst, nullptr);
        hCapsLock   = CreateWindowW(L"static", L"", WS_CHILD | SS_CENTER | SS_NOTIFY, 625, 25, 7, 5, hwnd, (HMENU)IDC_LED_CAPS, hInst, nullptr);
        hScrollLock = CreateWindowW(L"static", L"", WS_CHILD | SS_CENTER | SS_NOTIFY, 665, 25, 7, 5, hwnd, (HMENU)IDC_LED_SCROLL, hInst, nullptr);
    }

    if (!GetKeyboardState(lpKeyStates))
        return FALSE;

	/* Handle other keys. mostly letters and upper digit row */
    for (i = 0; i < nKeys; i++)
    {
        if (!Keys[i].lpText)
        {
            uVirtKey = MapVirtualKeyW(Keys[i].uID & 0xFF, MAPVK_VSC_TO_VK);
            ToUnicode(uVirtKey, Keys[i].uID & 0xFF, lpKeyStates, wKey, 2, 0);
            szKey = wKey;
        }
        else
        {
            szKey = Keys[i].lpText;
        }

        if (!bRefresh)
        {
            hKeys[i] = CreateWindowW(L"button", szKey,
                                     WS_CHILD | BS_PUSHBUTTON,
                                     Keys[i].x, Keys[i].y,
                                     Keys[i].cx, Keys[i].cy,
                                     hwnd, (HMENU)Keys[i].uID, hInst, nullptr);
            if (!hKeys[i])
                return FALSE;
        }
        else
        {
            SendMessage(hKeys[i], WM_SETTEXT, 0, reinterpret_cast<LPARAM>(szKey));
        }
    }
    return TRUE;
}
/* Release the key that is associated with the scancode */
VOID OSKKeyboard::ReleaseKey(WORD ScanCode)
{
    INPUT Input;
    BOOL bExtendedKey;
    HWND hWndControl;

    /* Is it a 2-states key ? */
    hWndControl = GetDlgItem(hwnd, ScanCode);

    if ((GetWindowLongPtrW(hWndControl, GWL_STYLE) & BS_AUTOCHECKBOX) != BS_AUTOCHECKBOX)
        return;

    /* Is the key down ? */
    if (SendMessageW(hWndControl, BM_GETCHECK, 0, 0) != BST_CHECKED)
        return;

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
}

/* Deconstructor */
OSKKeyboard::~OSKKeyboard()
{
    delete[] hUniqueKeys;
    delete[] hKeys;
}