#include "precomp.h"

/* Prototypes */
DWORD WINAPI LpkGetCharacterPlacement(HDC hdc, LPCWSTR lpString, INT uCount, INT nMaxExtent, 
                                      GCP_RESULTSW *lpResults, DWORD dwFlags, DWORD dwUnused);

BOOL WINAPI LpkExtTextOut(HDC hdc, int x, int y,
                          UINT fuOptions, const RECT *lprc, LPCWSTR lpString,
                          UINT uCount , const INT *lpDx, INT unknown);

void BidiTest(HDC hdc)
{
    const WCHAR szString[] = {ALEF, BET, GIMEL, DALET, HEY, 'A', 'B', 'C', 'D', VAV, ZAYIN, HET, TET, YUD, 0};
    const WCHAR szReversedString[] = {HEY, DALET, GIMEL, BET, ALEF, 'A', 'B', 'C', 'D', YUD, TET, HET, ZAYIN, VAV, 0};
    int Len = wcslen(szString);
    int i, xpos, tempLength;
    WCHAR tempString[20] = {0};
    WCHAR Glyphs[100] = {0};
    WCHAR OutString[100] = {0};
    INT lpCaretPos[100] = {0};
    UINT lpOrder[100] = {0};
    GCP_RESULTSW Results = {0};

    Results.lStructSize = sizeof(Results);
    Results.lpOutString = OutString;
    Results.lpGlyphs = Glyphs;
    Results.nGlyphs = 100;
    Results.lpCaretPos = lpCaretPos;
    Results.lpOrder = lpOrder;

    TextOutW(hdc, 10, 10, L"Proper (string being used):", 27);
    TextOutW(hdc, 200, 10, szString, 14);
    TextOutW(hdc, 10, 30, L"Reversed (example):", 19);
    TextOutW(hdc, 200, 30, szReversedString, 14);

    TextOutW(hdc, 10, 50, L"String with NULL LpkETO call (not reversed):", 44);
    LpkExtTextOut(hdc, 10, 70, 0, NULL, szString, Len, NULL, 0);

    TextOutW(hdc, 10, 90, L"String with ETO_IGNORELANGUAGE LpkETO call (not reversed):", 58);
    LpkExtTextOut(hdc, 10, 110, ETO_IGNORELANGUAGE, NULL, szString, Len, NULL, 0);

    TextOutW(hdc, 10, 130, L"String with GCP_REORDER and ETO_GLYPH_INDEX LpkGCP call (not reversed):", 71);
    LpkGetCharacterPlacement(hdc, szString, Len, 0, &Results, GCP_REORDER, 0);
    LpkExtTextOut(hdc, 10, 150, ETO_GLYPH_INDEX, NULL, Glyphs, Results.nGlyphs, NULL, 0);
    TextOutW(hdc, 10, 170, L"String with GCP_REORDER and ETO_IGNORELANGUAGE LpkGCP call (not reversed, lpOutString):", 87);
    ExtTextOutW(hdc, 10, 190, ETO_IGNORELANGUAGE, NULL, OutString, Results.nGlyphs, NULL);

    TextOutW(hdc, 10, 210, L"String without GCP_REORDER and ETO_GLYPH_INDEX LpkGCP call (reversed):", 70);
    LpkGetCharacterPlacement(hdc, szString, Len, 0, &Results, 0, 0);
    LpkExtTextOut(hdc, 10, 230, ETO_GLYPH_INDEX, NULL, Glyphs, Results.nGlyphs, NULL, 0);
    TextOutW(hdc, 10, 250, L"String without GCP_REORDER and ETO_IGNORELANGUAGE LpkGCP call (reversed, lpOutString):", 86);
    ExtTextOutW(hdc, 10, 270, ETO_IGNORELANGUAGE, NULL, OutString, Len, NULL);

    TextOutW(hdc, 10, 290, L"String with ETO_IGNORELANGUAGE ETO call (reversed, not Lpk direct call!):", 73);
    ExtTextOutW(hdc, 10, 310, ETO_IGNORELANGUAGE, NULL, szString, Len, NULL);

    TextOutW(hdc, 10, 330, L"String with ETO_RTLREADING LpkETO call (slight order change)", 60);
    LpkExtTextOut(hdc, 10, 350, ETO_RTLREADING, NULL, szString, Len, NULL, 0);

    TextOutW(hdc, 10, 370, L"String with ETO_RTLREADING ETO call (slight order change)", 57);
    ExtTextOutW(hdc, 10, 390, ETO_RTLREADING, NULL, szString, Len, NULL);

    GetCharacterPlacementW(hdc, szString, Len, 0, &Results, GCP_REORDER);
    TextOutW(hdc, 10, 410, L"Glyph positions with GCP_REORDER flag", 37);

    /* Prints per column the location of the character in the string, reordered location, its position and the character itself */
    for (i = 0, xpos = 10; i < Len; i++, xpos += 30)
    {
        StringCchPrintfW(tempString, 20, L"%d", i);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 430, tempString, tempLength);

        StringCchPrintfW(tempString, 20, L"%d", lpOrder[i]);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 450, tempString, tempLength);

        StringCchPrintfW(tempString, 20, L"%d", lpCaretPos[i]);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 470, tempString, tempLength);

        TextOutW(hdc, xpos, 490, &szString[i], 1);
    }
    TextOutW(hdc, xpos, 430, L"Character location", 18);
    TextOutW(hdc, xpos, 450, L"lpOrder[i]", 10);
    TextOutW(hdc, xpos, 470, L"lpCaretPos[i]", 13);
    TextOutW(hdc, xpos, 490, L"String[i]", 9);

    GetCharacterPlacementW(hdc, szString, Len, 0, &Results, 0);
    TextOutW(hdc, 10, 510, L"Glyph positions without GCP_REORDER flag", 40);

    for (i = 0, xpos = 10; i < Len; i++, xpos += 30)
    {
        StringCchPrintfW(tempString, 20, L"%d", i);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 530, tempString, tempLength);

        StringCchPrintfW(tempString, 20, L"%d", lpOrder[i]);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 550, tempString, tempLength);

        StringCchPrintfW(tempString, 20, L"%d", lpCaretPos[i]);
        tempLength = wcslen(tempString);
        TextOutW(hdc, xpos, 570, tempString, tempLength);

        TextOutW(hdc, xpos, 590, &szString[i], 1);
    }
    TextOutW(hdc, xpos, 530, L"Character location", 18);
    TextOutW(hdc, xpos, 550, L"lpOrder[i]", 10);
    TextOutW(hdc, xpos, 570, L"lpCaretPos[i]", 13);
    TextOutW(hdc, xpos, 590, L"String[i]", 9);
}
