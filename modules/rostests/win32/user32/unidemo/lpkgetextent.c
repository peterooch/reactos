#include "precomp.h"

BOOL WINAPI LpkGetTextExtentExPoint(HDC hdc, LPCWSTR lpString, INT cString, INT nMaxExtent, INT* lpnFit, INT* lpDx, SIZE* lpSize, DWORD dwUnused, INT unknown);
BOOL WINAPI GetTextExtentExPointWPri(HDC hdc, LPCWSTR lpwsz, INT cwc, INT dxMax, INT *pcCh, PINT pdxOut, LPSIZE psize);

void LPKGetExtentTest(HDC hdc)
{
    SIZE sz;
    WCHAR buffer[MAX_PATH] = {0};
    INT fit = 0, dx[10], i, j = 0;
    UINT  buffer_length; 
    HFONT hFont;
    WCHAR hebrew_txt1[20];
    WCHAR hebrew_txt2[20];
    WCHAR arabic_txt[20];
    GCP_RESULTSW gcp_res;
    WCHAR glyphs[10];
    SCRIPT_STRING_ANALYSIS ssa;
    BOOL result;

    LoadStringW(g_hInstance, 1, hebrew_txt1, 20);
    LoadStringW(g_hInstance, 2, hebrew_txt2, 20);
    LoadStringW(g_hInstance, 3, arabic_txt, 20);

    LpkGetTextExtentExPoint(hdc, L"Dummy text", 10, 0, &fit, NULL, &sz, 0, 0);
    StringCchPrintfW(buffer, MAX_PATH, L"LPK: For \"Dummy Text\" sz.x = %d, sz.y = %d, lpnFit = %d", sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 10, buffer, buffer_length);
    GetTextExtentExPointW(hdc, L"Dummy text", 10, 0, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"NOT LPK: For \"Dummy Text\" sz.x = %d, sz.y = %d, lpnFit = %d", sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 30, buffer, buffer_length);
    LpkGetTextExtentExPoint(hdc, hebrew_txt1, 7, 0, &fit, NULL, &sz, 0, 0);
    StringCchPrintfW(buffer, MAX_PATH, L"LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",hebrew_txt1, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 50, buffer, buffer_length);
    GetTextExtentExPointW(hdc, hebrew_txt1, 7, 0, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"NOT LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",hebrew_txt1, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 70, buffer, buffer_length);
    LpkGetTextExtentExPoint(hdc, hebrew_txt2, 15, 100, &fit, NULL, &sz, 0, 0);
    StringCchPrintfW(buffer, MAX_PATH, L"LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",hebrew_txt2, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 90, buffer, buffer_length);
    GetTextExtentExPointW(hdc, hebrew_txt2, 15, 100, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"NOT LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",hebrew_txt2, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 110, buffer, buffer_length);
    GetTextExtentExPointWPri(hdc, hebrew_txt2, 15, 100, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"WPri: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",hebrew_txt2, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 130, buffer, buffer_length);
    LpkGetTextExtentExPoint(hdc, arabic_txt, 9, 0, &fit, NULL, &sz, 0, 0);
    StringCchPrintfW(buffer, MAX_PATH, L"LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",arabic_txt, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 150, buffer, buffer_length);
    GetTextExtentExPointW(hdc, arabic_txt, 9, 0, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"NOT LPK: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",arabic_txt, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 170, buffer, buffer_length);
    GetTextExtentExPointWPri(hdc, arabic_txt, 9, 0, &fit, NULL, &sz);
    StringCchPrintfW(buffer, MAX_PATH, L"WPri: For \"%s\" sz.x = %d, sz.y = %d, lpnFit = %d",arabic_txt, sz.cx, sz.cy, fit);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 190, buffer, buffer_length);
    TextOutW(hdc, 10, 210, L"Dx comparison for arabic sample", 31);
    TextOutW(hdc, 10, 230, L"LpkGetTextExtentExPoint", 23);
    ZeroMemory(dx, sizeof(dx));
    LpkGetTextExtentExPoint(hdc, arabic_txt, 9, 250, &fit, dx, &sz, 0, 0);
    for (i = 0; i < 10; i++)
    {
        StringCchPrintfW(buffer, MAX_PATH, L"%d", dx[i]);
        StringCchLengthW(buffer, MAX_PATH, &buffer_length);
        TextOutW(hdc, 10 + (i - 1) * 30, 250, buffer, buffer_length);
    }
    StringCchPrintfW(buffer, MAX_PATH, L"size.cx = %d, size.cy = %d", sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 270, buffer, buffer_length);
    TextOutW(hdc, 10, 290, L"GetTextExtentExPointW", 21);
    ZeroMemory(dx, sizeof(dx));
    GetTextExtentExPointW(hdc, arabic_txt, 9, 250, &fit, dx, &sz);
    for (i = 0; i < 10; i++)
    {
        StringCchPrintfW(buffer, MAX_PATH, L"%d", dx[i]);
        StringCchLengthW(buffer, MAX_PATH, &buffer_length);
        TextOutW(hdc, 10 + (i - 1) * 30, 310, buffer, buffer_length);
    }
    StringCchPrintfW(buffer, MAX_PATH, L"size.cx = %d, size.cy = %d", sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 330, buffer, buffer_length);
    TextOutW(hdc, 10, 350, L"GetTextExtentExPointWPri", 24);
    ZeroMemory(dx, sizeof(dx));
    GetTextExtentExPointWPri(hdc, arabic_txt, 9, 250, &fit, dx, &sz);
    for (i = 0; i < 10; i++)
    {
        StringCchPrintfW(buffer, MAX_PATH, L"%d", dx[i]);
        StringCchLengthW(buffer, MAX_PATH, &buffer_length);
        TextOutW(hdc, 10 + (i - 1) * 30, 370, buffer, buffer_length);
    }
    StringCchPrintfW(buffer, MAX_PATH, L"size.cx = %d, size.cy = %d", sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 390, buffer, buffer_length);
    ZeroMemory(dx, sizeof(dx));
    ZeroMemory(glyphs, sizeof(glyphs));
    ZeroMemory(&gcp_res, sizeof(gcp_res));
    gcp_res.lpGlyphs = glyphs;
    gcp_res.nGlyphs = 10;
    GetCharacterPlacementW(hdc, arabic_txt, 9, 0, &gcp_res, GCP_REORDER | GCP_GLYPHSHAPE);
    TextOutW(hdc, 10, 410, L"GetTextExtentExPointI with GCPW", 32);
    GetTextExtentExPointI(hdc, (LPWORD)glyphs, gcp_res.nGlyphs, 250, &fit, dx, &sz);
    for (i = 0; i < 10; i++)
    {
        StringCchPrintfW(buffer, MAX_PATH, L"%d", dx[i]);
        StringCchLengthW(buffer, MAX_PATH, &buffer_length);
        TextOutW(hdc, 10 + (i - 1) * 30, 430, buffer, buffer_length);
    }
    StringCchPrintfW(buffer, MAX_PATH, L"size.cx = %d, size.cy = %d", sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 450, buffer, buffer_length);
    TextOutW(hdc, 10, 470, L"USP10 ScriptString", 18);
    ScriptStringAnalyse(hdc, arabic_txt, 9, 1.5 * 9 + 16, -1, SSA_GLYPHS, 0, NULL, NULL, NULL, NULL, NULL, &ssa);
    ScriptStringGetLogicalWidths(ssa, dx);
    for (i = 0; i < 9; i++)
    {
        j += dx[i];
        StringCchPrintfW(buffer, MAX_PATH, L"%d", j);
        StringCchLengthW(buffer, MAX_PATH, &buffer_length);
        TextOutW(hdc, 10 + (i - 1) * 30, 490, buffer, buffer_length);
    }
    result = LpkGetTextExtentExPoint(hdc, NULL, 10, 0, NULL, NULL, &sz, 0,0);
    StringCchPrintfW(buffer, MAX_PATH, L"LpkGetTextExtentExPoint(hdc, NULL, 10, 0, NULL, NULL, &sz, 0, 0) returned %d, sz.cx = %d, sz.cy = %d",
                     result, sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 510, buffer,buffer_length);
    result = LpkGetTextExtentExPoint(hdc, arabic_txt, 0, 0, NULL, NULL, &sz, 0,0);
    StringCchPrintfW(buffer, MAX_PATH, L"LpkGetTextExtentExPoint(hdc, %s, 0, 0, NULL, NULL, &sz, 0, 0) returned %d, sz.cx = %d, sz.cy = %d",
                     arabic_txt,result, sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 530, buffer,buffer_length);
    result = LpkGetTextExtentExPoint(hdc, arabic_txt, 10, 0, NULL, NULL, NULL, 0,0);
    StringCchPrintfW(buffer, MAX_PATH, L"LpkGetTextExtentExPoint(hdc, %s, 10, 0, NULL, NULL, NULL, 0, 0) returned %d, sz.cx = %d, sz.cy = %d",
                     arabic_txt,result, sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 550, buffer,buffer_length);
    result = LpkGetTextExtentExPoint(hdc, arabic_txt, -20, 0, NULL, NULL, &sz, 0,0);
    StringCchPrintfW(buffer, MAX_PATH, L"LpkGetTextExtentExPoint(hdc, %s, -20, 0, NULL, NULL, &sz, 0, 0) returned %d, sz.cx = %d, sz.cy = %d",
                     arabic_txt,result, sz.cx, sz.cy);
    StringCchLengthW(buffer, MAX_PATH, &buffer_length);
    TextOutW(hdc, 10, 570, buffer,buffer_length);
}