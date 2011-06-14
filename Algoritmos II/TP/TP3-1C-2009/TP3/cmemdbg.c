
/*************************************************************************************************
	This file is part of cMemDbg

	Copyright (C)2009 Ezequiel Gastón Miravalles

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************************************/


/*************************************************************************************************
Software: cMemDbg
File: cmemdbg.c
Version: 1.0
Author: Ezequiel Gastón Miravalles
Website: http://www.neoegm.com/software/cmemdbg/
License: GNU GPL v3 (attached, read above)

Notes: Read cmemdbg.h notes.
*************************************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define	PRINT_OPERATIONS	0
#define MAX_ALLOC			256

int g_nAllocMem = 0;
struct DataAlloc
{
	void *pData;
	int nBytes;
	char *pszFile;
	int nLine;
} g_pAllocData[MAX_ALLOC] = {0};

int FreeAllocDataBytes(void *pPointer, char **ppszFile, int *pnLine)
{
	int i;

	if (!pPointer)
		return 0;

	for (i = 0; i < MAX_ALLOC; i++)
		if (g_pAllocData[i].pData == pPointer)
		{
			g_pAllocData[i].pData = 0;		/*Free position*/

			g_nAllocMem -= g_pAllocData[i].nBytes;

			if (ppszFile)
				*ppszFile = g_pAllocData[i].pszFile;

			if (pnLine)
				*pnLine = g_pAllocData[i].nLine;

			return g_pAllocData[i].nBytes;
		}

	return 0;
}

void AddAllocDataBytes(void *pPointer, size_t size, char *pszFile, int nLine)
{
	int i;

	if (!pPointer)
		printf(">MEM_ERROR\tCould not allocate %d bytes\n", size);

	for (i = 0; i < MAX_ALLOC; i++)
		if (!g_pAllocData[i].pData)
		{
			g_pAllocData[i].pData = pPointer;
			g_pAllocData[i].nBytes = size;
			g_pAllocData[i].pszFile = pszFile;
			g_pAllocData[i].nLine = nLine;
			g_nAllocMem += size;
			return;
		}

	printf(">INTERNAL_ERROR\tAllocation stack overflow, please increase MAX_ALLOC\n");
}

void DumpUnfreedBlocks()
{
	int i;
/*
	for (i = 0; i < MAX_ALLOC; i++)
		if (g_pAllocData[i].pData)
			printf(">INFO\tUnfreed block %.8X of %d bytes [%s:%d]\n", g_pAllocData[i].pData, g_pAllocData[i].nBytes, g_pAllocData[i].pszFile, g_pAllocData[i].nLine);
*/}

void * mallocb(size_t size, char *pszFile, int nLine)
{
	void * pRet = malloc(size);

	if (PRINT_OPERATIONS)
		printf(">A\t%.8X\t%d [%s:%d]\n", pRet, size, pszFile, nLine);

	AddAllocDataBytes(pRet, size, pszFile, nLine);

	return pRet;
}

void * callocb(size_t num, size_t size, char *pszFile, int nLine)
{
	void * pRet = calloc(num, size);

	if (PRINT_OPERATIONS)
		printf(">CA\t%.8X\t%d (%d x %d) [%s:%d]\n", pRet, num*size, num, size, pszFile, nLine);

	AddAllocDataBytes(pRet, num*size, pszFile, nLine);

	return pRet;
}

void freeb(void *memblock, char *pszFile, int nLine)
{
	int nBytes;
	char * pszOldFile = NULL;
	int nOldLine = 0;

	if (memblock)
	{
		nBytes = FreeAllocDataBytes(memblock, &pszOldFile, &nOldLine);

		if (PRINT_OPERATIONS)
			printf(">F\t%.8X\t%d (%s:%d) [%s:%d]\n", memblock, nBytes, pszOldFile, nOldLine, pszFile, nLine);

		if (!nBytes)
			printf(">ERROR\tTrying to free unallocated memory: %.8X\n", memblock);
	}

	free(memblock);
}

void * reallocb(void *memblock, size_t size, char *pszFile, int nLine)
{
	void * pRet = realloc(memblock, size);

	int nBytes = FreeAllocDataBytes(memblock, NULL, NULL);
	AddAllocDataBytes(pRet, size, pszFile, nLine);

	if (memblock && !nBytes)
		printf(">ERROR\tTrying to free unallocated memory while reallocating: %.8X\n", memblock);

	if (PRINT_OPERATIONS)
		if (memblock)
			printf(">R\t%.8X => %.8X\t%d => %d [%s:%d]\n", memblock, pRet, nBytes, size, pszFile, nLine);
		else
			printf(">R(A)\t%.8X\t%d [%s:%d]\n", pRet, size, pszFile, nLine);

	return pRet;
}

void PrintMemoryLeakInfo()
{
	if (g_nAllocMem == 0)
		printf(">INFO\tNo memory leaks detected\n");
	else if (g_nAllocMem < 0)
		printf(">INFO\tPROBLEM: There was more freed memory than allocated (%d bytes) [This shouldn't happen]\n", g_nAllocMem);
	else
		printf(">INFO\tPROBLEM: Memory leak found (%d bytes)\n", g_nAllocMem);

	DumpUnfreedBlocks();
}
