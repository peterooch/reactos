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


LPWSTR BiDi_string(
	LPWSTR lpinString, UINT count)
{
	LPWSTR workstr;
	LPWSTR retstr;
	FriBidiCharType biditypes;
	FriBidiParType basedir;
	FriBidiLevel embeddinglevels;
	FriBidiStrIndex len;
	FriBidiStrIndex off;

	for (len == 0; len <= count; len++)
	{
		wcscat(workstr, lpinString[len]);

		if (lpinString[len] == '\n' || len == count)
		{
			fribidi_get_bidi_types(workstr; len; biditypes);
			fribidi_get_par_embedding_levels(biditypes, off, basedir, embeddinglevels);
			off = sizeof(workstr) - 1;

			fribidi_reorder_line(FRIBIDI_FLAGS_DEFAULT, biditypes, off, 0, basedir, embeddinglevels, workstr, NULL);

			wcscat(retstr, workstr);
			wcscpy(workstr, L"");
			continue;
		}

	}
	return retstr;
}
