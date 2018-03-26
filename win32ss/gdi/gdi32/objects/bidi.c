/*
 * PROJECT:     ReactOS GDI32
 * LICENSE:     GPL-2.0+ (https://spdx.org/licenses/GPL-2.0+)
 * PURPOSE:     BiDirectional Text Support API.
 * COPYRIGHT:   Copyright 2018 Fribidi project https://github.com/fribidi/fribidi
 */
#include "fribidi/fribidi.h"
#include "bidi.h"
#include "precomp.h"

BOOL BiDi_string(
	LPWSTR lpinString, UINT uCount)
{
	//Variables
	FriBidiChar workstr[256];
	FriBidiChar retstr[uCount];
	FriBidiCharType *biditypes = NULL;
	FriBidiParType *basedir;
	FriBidiLevel *embeddinglevels = NULL;
	FriBidiStrIndex len;
	FriBidiStrIndex off;
	FriBidiStrIndex retcount = 0;
	FriBidiStrIndex i = 0;
	WCHAR szOutString[uCount];

	//Main Loop, goes character by character
	for (len == 0; len <= uCount; len++)
	{
		//Copy character to temporary line string
		workstr[len] = (FriBidiChar)lpinString[len];

		//if newline detected or reached end of string
		if ((WCHAR)lpinString[len] == L"\n" || len == uCount)
		{
			off = sizeof(workstr);
			biditypes = malloc(off * sizeof biditypes[0]);
			embeddinglevels = malloc(off * sizeof embeddinglevels[0]);

			fribidi_get_bidi_types(workstr, len, biditypes);
			fribidi_get_par_embedding_levels(biditypes, off, basedir, embeddinglevels);
			

			fribidi_reorder_line(FRIBIDI_FLAGS_DEFAULT, biditypes, off, 0, basedir, embeddinglevels, workstr, NULL);

			//now copy the temporary line string to the main "processing" string
			for (i = 0; i <= off; i++, retcount++)
			{
				retstr[retcount] = workstr[i];
			}
			continue;

			free(biditypes);
			free(embeddinglevels);
		}

	}
	//now making the main "processing string" into a LPWSTR
	for (i = 0; i <= uCount; i++)
	{
		szOutString[i] = (WCHAR)retstr[i];
	}

	wcscpy_s(lpinString, uCount, szOutString);
	return TRUE;
}
