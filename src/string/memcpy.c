#include <string.h>

#ifndef MEMCPY
#define MEMCPY __memcpy
#endif

void	*MEMCPY(void *dst0, const void *src0, size_t n) {
	char *d = dst0 ;
	const char *s = src0;
	while (n--)
		*d++ = *s++;
	return dst0;
}

weak_alias(MEMCPY, memcpy);