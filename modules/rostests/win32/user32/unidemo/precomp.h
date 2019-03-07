#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <strsafe.h>
#include <usp10.h>

extern HINSTANCE g_hInstance;

void BidiTest(HDC hdc);
void PSMTest(HDC hdc);
void LPKGetExtentTest(HDC hdc);

enum {
    ALEF = 0x5D0,
    BET,
    GIMEL,
    DALET,
    HEY,
    VAV,
    ZAYIN,
    HET,
    TET,
    YUD,
    KAF_SOFIT,
    KAF,
    LAMED,
    MEM_SOFIT,
    MEM,
    NUN_SOFIT,
    NUN,
    SAMEKH,
    AYIN,
    PEY_SOFIT,
    PEY,
    TSADI_SOFIT,
    TSADI,
    QOF,
    RESH,
    SHIN,
    TAV
};
