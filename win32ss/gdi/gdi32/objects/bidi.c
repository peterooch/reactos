/*
 * PROJECT:     ReactOS GDI32
 * LICENSE:     GPL-2.0+ (https://spdx.org/licenses/GPL-2.0+)
 * PURPOSE:     BiDirectional Text Support API.
 * COPYRIGHT:   Copyright 2018 Fribidi project https://github.com/fribidi/fribidi
 *              
 */
#include "fribidi/fribidi.h"
#include "bidi.h"
#include "precomp.h"
 
LPCWSTR BiDi_string(
    LPCWSTR lpinString, UINT count)
{
    LPCWSTR workstr = lpString;
    LPCWSTR retstr;
    FriBidiCharType biditypes;
    FriBidiParType base_dir;
    FriBidiLevel embedding_levels;
    

    
    
    fribidi_reorder_line (
  /* input */
  FriBidiFlags flags, /* reorder flags */
  const FriBidiCharType *bidi_types, //fribidi_get_bidi_types()
  const FriBidiStrIndex len,
  const FriBidiStrIndex off,
  const FriBidiParType base_dir,
  /* input and output */
  FriBidiLevel *embedding_levels,//fribidi_get_par_embedding_levels
  workstr,
  /* output */
  NULL;
)
