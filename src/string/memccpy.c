#include <string.h>


#undef __memccpy
#undef memccpy

#ifdef memccpy
# define __memccpy MEMCCPY
#endif


void    *__memccpy(void *dest, const void *src, int c, size_t n) {
	void *p = memchr(src, c, n);
	if (p != NULL)
		return __mempcpy(dest, src, p - src + 1);
	memcpy(dest, src, n);
	return NULL;
}

weak_alias(__memccpy, memccpy);