/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * FILE:            base/applications/osk/main.cpp
 * PURPOSE:         On screen keyboard - program entrypoint
 * PROGRAMMERS:     Denis ROBERT
 * 					Bișoc George
 * 					Baruch Rutman
 */
#include "osk.hpp"

int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd)
{
    OSKWindow MainWindow;
    HANDLE hMutex;
    INITCOMMONCONTROLSEX iccex;
    MSG msg;

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nShowCmd);

    OSKBase::hInst = hInstance;

    hMutex = CreateMutexW(nullptr, FALSE, L"OSKRunning");

    if (hMutex && GetLastError() == ERROR_ALREADY_EXISTS)
    {
        CloseHandle(hMutex);
        return 0;
    }

    iccex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    iccex.dwICC = ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES;
    InitCommonControlsEx(&iccex);

    if (!MainWindow.Init())
    {
        if (hMutex)
            CloseHandle(hMutex);

        return 0;
    }

    while (GetMessageW(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    if (hMutex)
        CloseHandle(hMutex);

	MainWindow.Cleanup();

    return 0;
}
