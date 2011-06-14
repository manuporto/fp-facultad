
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void *mallocb(size_t size)
{
	void * pRet = malloc(size);

	printf(">A\t%.8X\t%d\n", pRet, size);

	return pRet;
}

void freeb(void *memblock)
{
	printf(">F\t%.8X\n", memblock);

	free(memblock);
}
