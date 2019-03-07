#include "precomp.h"

typedef void (*pfnDemo)(HDC hdc);
HINSTANCE g_hInstance;
HMENU g_hMenu;
LPCWSTR DemoClass = L"DemoClass";
UINT uSelectedDemo = 0;

struct {
    pfnDemo DemoFunction;
    LPCWSTR TestName;
} DemoFunctions[] = {
    {BidiTest,         L"BiDi Text Demo"},
    {PSMTest,          L"(User)LpkPSMTextOut Demo"},
    {LPKGetExtentTest, L"LpkGetTextExtentExPoint Demo"}
};
#define NUMTESTS (sizeof(DemoFunctions)/sizeof(DemoFunctions[0]))

LRESULT CALLBACK MainDemoProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    LOGFONTW logfont;
    HFONT hfont;

    switch (uMsg)
    {
        case WM_CREATE:
        {
            HMENU hMenuBar;
            INT i;

            hMenuBar = CreateMenu();
            g_hMenu = CreateMenu();

            for (i = 1; i <= NUMTESTS; i++)
                AppendMenuW(g_hMenu, MF_STRING, i, DemoFunctions[i - 1].TestName);

            CheckMenuRadioItem(g_hMenu, 1, NUMTESTS, 1, MF_BYCOMMAND);
            AppendMenuW(hMenuBar, MF_POPUP, (UINT_PTR)g_hMenu, L"Tests");
            SetMenu(hwnd, hMenuBar);
        }
        case WM_PAINT:
        {
            hdc = BeginPaint(hwnd, &ps);

            ZeroMemory(&logfont, sizeof(logfont));
            StringCchCopyW(logfont.lfFaceName, LF_FACESIZE, L"Microsoft Sans serif");
            hfont = CreateFontIndirectW(&logfont);

            if (hfont)
                SelectObject(hdc, hfont);

            SetBkMode(hdc, TRANSPARENT);
            DemoFunctions[uSelectedDemo].DemoFunction(hdc);

            EndPaint(hwnd, &ps);
            return TRUE;
        }   
        case WM_COMMAND:
            if (LOWORD(wParam) <= NUMTESTS)
            {
                uSelectedDemo = LOWORD(wParam) - 1;
                CheckMenuRadioItem(g_hMenu, 1, NUMTESTS, LOWORD(wParam), MF_BYCOMMAND);
                InvalidateRect(hwnd, NULL, TRUE);
                return TRUE;
            }
        case WM_CLOSE:
        case WM_DESTROY:
            PostQuitMessage(FALSE);
            return FALSE;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPWSTR lpCmdLn, int nCmd)
{
    WNDCLASSEXW wc;
    HWND DemoWnd;
    MSG msg;

    g_hInstance = hInst;

    ZeroMemory(&wc, sizeof(wc));

    wc.lpfnWndProc   = MainDemoProc;
    wc.lpszClassName = DemoClass;
    wc.hInstance     = g_hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.cbSize        = sizeof(wc);
    wc.style         = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassExW(&wc))
        return 0;

    DemoWnd = CreateWindowExW(0L,
                              DemoClass,
                              L"UI Demo Program",
                              WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_THICKFRAME,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              900,
                              900,
                              NULL,
                              NULL,
                              g_hInstance,
                              NULL);

    if (!DemoWnd)
        return 0;
    
    ShowWindow(DemoWnd, SW_SHOW);
    UpdateWindow(DemoWnd);

    while (GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnregisterClassW(DemoClass, g_hInstance);
    return 0;
}