/*
 * PROJECT:         ReactOS On-Screen Keyboard
 * LICENSE:         GPL - See COPYING in the top level directory
 * PURPOSE:         On screen keyboard.
 * COPYRIGHT:       Denis ROBERT
 *                  Copyright 2019 Bișoc George (fraizeraust99 at gmail dot com)
 * 					Baruch Rutman (C++ interfaces)
 */

#ifndef _OSK_HPP
#define _OSK_HPP

/* INCLUDES ******************************************************************/
#include <windows.h>
#include <commctrl.h>
#include <strsafe.h>
#include "osk_res.h"

#define KB_NORMAL_CX 570
#define KB_ENHANCED_CX 700
#define KB_NORMAL_CY 250
#define RET_BOOL 1
#define RET_INT  2
#define UPDATE_LAYOUT 1
#define UPDATE_LANG 2

/* Object Interfaces */
/* Base object class */
class OSKBase
{
public:
    /* Shared WindowProc Function */
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    /* WindowProc */
    virtual LRESULT ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    /* Update font, show and update window */
    static VOID RevealWindow(HWND hwnd);
    virtual ~OSKBase() {}

	/* Primary Object window handle */
    HWND hwnd;
    /* Shared handles */
    static HINSTANCE hInst;
    static HFONT hFont;
};

/* Keyboard subwindow object class */
class OSKKeyboard : OSKBase
{
public:
    /* WindowProc */
    virtual LRESULT ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    /* Initialize Primary Keyboard sub-window*/
    HWND Init(HWND hWndParent);
    /* Initialize individual keys */
    BOOL InitKeys(BOOL bRefresh);
    virtual ~OSKKeyboard();

    /* Pointer to bSoundClick in OSKWindow*/
    LPBOOL bSoundClick;
private:
    /* Handles for individual keys, brushes, timers */
    HWND* hUniqueKeys;
    HWND* hKeys;
    HWND hCapsLock, hNumLock, hScrollLock;
    HWND hCapsText, hNumText, hScrollText;
    HWND hActiveWindow;
    HBRUSH hBrushGreenLed, hBrushStatic;
    UINT_PTR timer;

    VOID ReleaseKey(WORD ScanCode);
    LRESULT OnCommand(WPARAM wParam, LPARAM lParam);
};

/* Primary window object class */
class OSKWindow : OSKBase
{
public:
    /* Initialize method */
    BOOL Init();
    /* WindowProc */
    virtual LRESULT ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    static INT_PTR CALLBACK WarningDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	VOID Cleanup();

private:
    OSKKeyboard* Keyboard;
    HWND hwndKeyboard;
    BOOL bIsEnhancedKB = TRUE;
    BOOL bShowWarning = TRUE;
    BOOL bSoundClick = FALSE;
    WCHAR szCaption[MAX_PATH];
    HICON hIcon;
    SIZE szDim;
    POINT ptPos = { CW_USEDEFAULT, CW_USEDEFAULT };

    LRESULT OnCommand(WPARAM wParam, LPARAM lParam);
    LRESULT UpdateKeyboard(INT iReason, WORD wParam);
    VOID LoadSettings();
    INT QueryValue(HKEY hKey, LPCWSTR lpszValue, INT ret_type, INT def_val);
    VOID SaveSettings();
    VOID SaveValue(HKEY hKey, LPCWSTR lpszValue, INT value);
};

#endif

/* EOF */
