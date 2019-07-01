/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * FILE:            base/applications/osk/base.cpp
 * PURPOSE:         On screen keyboard base object implementation
 * PROGRAMMERS:     Baruch Rutman
 */
#include "osk.hpp"

HINSTANCE OSKBase::hInst = nullptr;
HFONT OSKBase::hFont = nullptr;

/* Update font, show and update window */
VOID OSKBase::RevealWindow(HWND hwnd)
{
    if (hFont)
        SendMessageW(hwnd, WM_SETFONT, reinterpret_cast<WPARAM>(hFont), 0);

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}
/* Shared WindowProc method */
LRESULT CALLBACK OSKBase::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    OSKBase* This;

    /* Extract and save object pointer */
    if (uMsg == WM_NCCREATE)
    {
        This = static_cast<OSKBase*>(reinterpret_cast<LPCREATESTRUCTW>(lParam)->lpCreateParams);
        if (This)
            This->hwnd = hwnd;

        SetLastError(0);
        if (!SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(This)) && GetLastError() != 0)
            return FALSE;
    }
    else
    {
        This = reinterpret_cast<OSKBase*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    /* Send the message to its respective object virtual method */
    if (This)
        return This->ProcessMessage(uMsg, wParam, lParam);

    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}

LRESULT OSKBase::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    /*Base object doesn't have anything*/
    return FALSE;
}
