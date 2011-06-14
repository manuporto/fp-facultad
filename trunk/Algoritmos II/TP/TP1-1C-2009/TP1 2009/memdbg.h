
#include <stdlib.h>

#define malloc mallocb
#define free freeb

void *mallocb(size_t size);
void freeb(void *memblock);
