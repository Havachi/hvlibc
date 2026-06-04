#include <string.h>

#undef __memcpy
#undef memcpy

#ifndef MEMCPY
#define MEMCPY __memcpy
#endif

void	*__memcpy(void *dst0, const void *src0, size_t n) {
	char *d = dst0 ;
	const char *s = src0;
	while (n--)
		*d++ = *s++;
	return dst0;
}

weak_alias(__memcpy, memcpy);