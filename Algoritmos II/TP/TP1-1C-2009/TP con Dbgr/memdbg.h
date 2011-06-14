
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
