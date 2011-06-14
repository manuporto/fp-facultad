
/*************************************************************************************************
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
File: cmemdbg.h
Version: 1.0
Author: Ezequiel Gastón Miravalles
Website: http://www.neoegm.com/software/cmemdbg/
License: GNU GPL v3 (attached, read above)

Notes: Include this file after the standard headers in every file in which you allocate or free
       memory. Supported functions: malloc, realloc, calloc, free.

	   You can tweak the macro preprocessor definitions on cmemdbg.c to customize the behaviour:
			PRINT_OPERATIONS
				Function: output to stdout every operation (alloc or free) done.
				Valid values
					0   Just output errors and notifications
					1   Output every operation, errors and notifications
			MAX_ALLOC
				Function: memory track stack array element count
				Valid values: integers higher than 0

		To get a final dump of memory leaks, you should call PrintMemoryLeakInfo() just before
		your program exits.
*************************************************************************************************/


#include <stdlib.h>

/*Redefines*/
#define malloc(size) mallocb(size, __FILE__, __LINE__)
#define free(memblock) freeb(memblock, __FILE__, __LINE__)
#define realloc(memblock, size) reallocb(memblock, size, __FILE__, __LINE__)
#define calloc(num, size) callocb(num, size, __FILE__, __LINE__)

/*Functions*/
void PrintMemoryLeakInfo();

/*Redefined functions*/
void * mallocb(size_t size, char *pszFile, int nLine);
void freeb(void *memblock, char *pszFile, int nLine);
void * reallocb(void *memblock, size_t size, char *pszFile, int nLine);
void * callocb(size_t num, size_t size, char *pszFile, int nLine);
