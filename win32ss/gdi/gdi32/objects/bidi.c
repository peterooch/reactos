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


BOOL BiDi_string(
	LPWSTR lpinString, UINT count)
{
	//Variables
	FriBidiChar workstr[256];
	FriBidiChar retstr[count];
	FriBidiCharType *biditypes;
	FriBidiParType *basedir;
	FriBidiLevel *embeddinglevels;
	FriBidiStrIndex len;
	FriBidiStrIndex off;
	FriBidiStrIndex retcount = 0;
	int i = 0;
	WCHAR outstring[count];

	//Main Loop
	for (len == 0; len <= count; len++)
	{
		//Copy character to temporary line string
		workstr[len] = (FriBidiChar)lpinString[len];

		//if newline detected or reached end of string
		if (lpinString[len] == '\n' || len == count)
		{
			fribidi_get_bidi_types(workstr; len; biditypes);
			fribidi_get_par_embedding_levels(biditypes, off, basedir, embeddinglevels);
			off = sizeof(workstr);

			fribidi_reorder_line(FRIBIDI_FLAGS_DEFAULT, biditypes, off, 0, basedir, embeddinglevels, workstr, NULL);

			//now copy the temporary line string to the main "processing" string
			for (i = 0; i <= off; i++, retcount++)
			{
				retstr[retcount] = workstr[i];
			}
			workstr = NULL;
			continue;
		}

	}
	//now making the main "processing string" into a LPWSTR
	for (i = 0; i <= count; i++)
	{
		outstring[i] = (WCHAR)retstr[i];
	}

	wcscpy(lpinString, outstring);
	return TRUE;
}
