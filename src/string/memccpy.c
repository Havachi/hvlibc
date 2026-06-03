#include <string.h>

void    *memccpy(void *dest, const void *src, int c, size_t n) {
	void *p = memchr(src, c, n);
	if (p != NULL)
		return mempcpy(dest, src, p-src + 1);
	memcpy(dest, src, n);
	return NULL;
}