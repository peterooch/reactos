
#include "osk.h"
#include "keydata.h"
#define STRING_FONT 0
#define KB_NORMAL_CX 570
#define KB_ENHANCED_CX 700
#define KB_NORMAL_CY 250
LRESULT APIENTRY OSK_KeyboardProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL OSK_SetKeys(HWND hwnd, BOOL bRefresh);

BOOL OSK_KeyboardCreate(HWND hwndParent)
{
    WNDCLASSEXW wc = { 0 };

    wc.lpfnWndProc = OSK_KeyboardProc;
    wc.hInstance = Globals.hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"OSKKeyboard";
    wc.cbSize = sizeof(WNDCLASSEXW);

    if (!RegisterClassExW(&wc))
            return FALSE;

	/* Create primary keyboard window, at max possible size */
    Globals.hKeyboardWnd = CreateWindowExW(WS_EX_NOPARENTNOTIFY, L"OSKKeyboard", NULL,
                                           WS_CHILD | WS_CLIPCHILDREN,
                                           0, 0, KB_ENHANCED_CX, KB_NORMAL_CY,
                                           hwndParent, NULL, Globals.hInstance, NULL);

    if (!Globals.hKeyboardWnd)
        return FALSE;

    return TRUE;
}
LRESULT APIENTRY OSK_KeyboardProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            Globals.hKeys = HeapAlloc(GetProcessHeap(), 0, sizeof(HWND) * countof(Keys));

            if (!Globals.hKeys)
            {
                return -1;
            }

            Globals.hUniqueKeys = HeapAlloc(GetProcessHeap(), 0, sizeof(HWND) * countof(UniqueKeys));
    
            if (!Globals.hUniqueKeys)
            {
                HeapFree(GetProcessHeap(), 0, Globals.hKeys);
                return -1;
            }

            /* Create keys */
            if (!OSK_SetKeys(hwnd, FALSE))
            {
                HeapFree(GetProcessHeap(), 0, Globals.hUniqueKeys);
                HeapFree(GetProcessHeap(), 0, Globals.hKeys);
                return -1;
            }
            return TRUE;
        }
        case WM_PAINT:
        {
            UINT i;
            HDC hdc;
            HBRUSH hOldBrush;
            HFONT hOldFont;
            PAINTSTRUCT ps;

			/* Show all the buttons */
            for (i = 0; i < countof(UniqueKeys); i++)
            {
                ShowWindow(Globals.hUniqueKeys[i], SW_SHOW);
                UpdateWindow(Globals.hUniqueKeys[i]);
            }

            for (i = 0; i < countof(Keys); i++)
            {
                ShowWindow(Globals.hKeys[i], SW_SHOW);
                UpdateWindow(Globals.hKeys[i]);
            }

            hdc = BeginPaint(hwnd, &ps);

            hOldFont = SelectObject(hdc, Globals.hFont);

            /* Draw LEDs */
            TextOutW(hdc, 575, 5, L"Num", 3);
            TextOutW(hdc, 615, 5, L"Caps", 4);
            TextOutW(hdc, 655, 5, L"Scroll", 6);

            SelectObject(hdc, hOldFont);

            if (GetKeyState(VK_NUMLOCK) & 0x0001)
                hOldBrush = SelectObject(hdc, Globals.hBrushGreenLed);
            else
                hOldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));

            PatBlt(hdc, 585, 25, 7, 5, PATCOPY);
            SelectObject(hdc, hOldBrush);

            if (GetKeyState(VK_CAPITAL) & 0x0001)
                hOldBrush = SelectObject(hdc, Globals.hBrushGreenLed);
            else
                hOldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));

            PatBlt(hdc, 625, 25, 7, 5, PATCOPY);
            SelectObject(hdc, hOldBrush);

            if (GetKeyState(VK_SCROLL) & 0x0001)
                hOldBrush = SelectObject(hdc, Globals.hBrushGreenLed);
            else
                hOldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));

            PatBlt(hdc, 665, 25, 7, 5, PATCOPY);
            SelectObject(hdc, hOldBrush);

            EndPaint(hwnd, &ps);
            return TRUE;
        }
        case WM_COMMAND:
        {
            return OSK_Command(wParam, (HWND)lParam);
        }
        case WM_INPUTLANGCHANGE:
        case WM_INPUTLANGCHANGEREQUEST:
        {
            /* Refresh Keyboard according to the layout switch */
            OSK_SetKeys(hwnd, TRUE);
            InvalidateRect(hwnd, NULL, FALSE);
            return TRUE;
        }
        case WM_DESTROY:
        case WM_CLOSE:
        {
            UINT i;
            /* Release Ctrl, Shift, Alt keys */
            OSK_ReleaseKey(hwnd, SCAN_CODE_44); // Left shift
            OSK_ReleaseKey(hwnd, SCAN_CODE_57); // Right shift
            OSK_ReleaseKey(hwnd, SCAN_CODE_58); // Left ctrl
            OSK_ReleaseKey(hwnd, SCAN_CODE_60); // Left alt
            OSK_ReleaseKey(hwnd, SCAN_CODE_62); // Right alt
            OSK_ReleaseKey(hwnd, SCAN_CODE_64); // Right ctrl

            /* Destroy key controls */
            for (i = 0; i < countof(UniqueKeys); i++)
                DestroyWindow(Globals.hUniqueKeys[i]);

            for (i = 0; i < countof(Keys); i++)
                DestroyWindow(Globals.hKeys[i]);

            HeapFree(GetProcessHeap(), 0, Globals.hUniqueKeys);
            HeapFree(GetProcessHeap(), 0, Globals.hKeys);

            DestroyWindow(hwnd);
            return TRUE;
        }
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

BOOL OSK_SetKeys(HWND hwnd, BOOL bRefresh)
{
    HICON hIcon;
    LOGFONTW logfont = { 0 };
    LPCWSTR szKey;
    WCHAR wKey[2] = { 0 };
    UINT i, j, uVirtKey;
    BYTE lpKeyStates[256];

    if (!Globals.hFont)
    {
        if (!LoadStringW(Globals.hInstance, STRING_FONT, logfont.lfFaceName, LF_FACESIZE))
            StringCchCopyW(logfont.lfFaceName, LF_FACESIZE, L"MS Shell Dlg");

        logfont.lfHeight = 16;
        Globals.hFont = CreateFontIndirectW(&logfont);

        if (Globals.hFont)
            SendMessageW(hwnd, WM_SETFONT, (WPARAM)Globals.hFont, 0);
    }

    if (!GetKeyboardState(lpKeyStates))
        return FALSE;

    if (!bRefresh)
    {
	    /* Handle unique keys. modifier keys, start key, and others */
        for (i = 0; i < countof(UniqueKeys); i++)
        {
            Globals.hUniqueKeys[i] = CreateWindowExW(WS_EX_NOPARENTNOTIFY, L"button", UniqueKeys[i].lpText,
                                                     WS_CHILD | UniqueKeys[i].uFlags,
                                                     UniqueKeys[i].x, UniqueKeys[i].y,
                                                     UniqueKeys[i].cx, UniqueKeys[i].cy,
                                                     hwnd, (HMENU)UniqueKeys[i].uID, Globals.hInstance, NULL);
			if (!Globals.hUniqueKeys[i])
			{
				for (j = 0; j < i; j++)
					DestroyWindow(Globals.hUniqueKeys[j]);

				return FALSE;
			}

            if (UniqueKeys[i].uResource != 0)
            {
                hIcon = (HICON)LoadImageW(Globals.hInstance, MAKEINTRESOURCEW(UniqueKeys[i].uResource),
                                          IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
                if (hIcon)
                    SendMessageW(Globals.hUniqueKeys[i], BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);
            }
            else if (Globals.hFont)
            {
                SendMessageW(Globals.hUniqueKeys[i], WM_SETFONT, (WPARAM)Globals.hFont, 0);
            }
        }
    }

	/* Handle other keys. mostly letters and upper digit row */
    for (i = 0; i < countof(Keys); i++)
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
            Globals.hKeys[i] = CreateWindowExW(WS_EX_NOPARENTNOTIFY, L"button", szKey,
                                               WS_CHILD | BS_PUSHBUTTON,
                                               Keys[i].x, Keys[i].y,
                                               Keys[i].cx, Keys[i].cy,
                                               hwnd, (HMENU)Keys[i].uID, Globals.hInstance, NULL);
			if (!Globals.hKeys[i])
			{
				for (j = 0; j < countof(UniqueKeys); j++)
					DestroyWindow(Globals.hUniqueKeys[j]);

				for (j = 0; j < i; j++)
					DestroyWindow(Globals.hKeys[j]);

				return FALSE;
			}

            if (Globals.hFont)
                SendMessageW(Globals.hKeys[i], WM_SETFONT, (WPARAM)Globals.hFont, 0);
        }
        else
        {
            SendMessageW(Globals.hKeys[i], WM_SETTEXT, 0, (LPARAM)szKey);
        }
    }
    return TRUE;
}
