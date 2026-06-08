#include <string.h>

#undef mempcpy
#undef __mempcpy

#ifndef MEMPCPY
#define MEMPCPY __mempcpy
#endif

void *MEMPCPY (void *dest, const void *src, size_t len) {
	return memcpy(dest, src, len);
}

weak_alias(__mempcpy, mempcpy);