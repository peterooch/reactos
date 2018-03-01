/*
 * GDI definitions
 *
 * Copyright 1993 Alexandre Julliard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_GDI_PRIVATE_H
#define __WINE_GDI_PRIVATE_H

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include "windef.h"
#include "winbase.h"
#include "wingdi.h"




/* bidi.c */

/* Wine_GCPW Flags */
/* Directionality -
 * LOOSE means taking the directionality of the first strong character, if there is found one.
 * FORCE means the paragraph direction is forced. (RLE/LRE)
 */
#define WINE_GCPW_FORCE_LTR 0
#define WINE_GCPW_FORCE_RTL 1
#define WINE_GCPW_LOOSE_LTR 2
#define WINE_GCPW_LOOSE_RTL 3
#define WINE_GCPW_DIR_MASK 3
#define WINE_GCPW_LOOSE_MASK 2

extern BOOL BIDI_Reorder( HDC hDC, LPCWSTR lpString, INT uCount, DWORD dwFlags, DWORD dwWineGCP_Flags,
                          LPWSTR lpOutString, INT uCountOut, UINT *lpOrder, WORD **lpGlyphs, INT* cGlyphs );


#endif /* __WINE_GDI_PRIVATE_H */