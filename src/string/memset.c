#include <string.h>



#undef memset
#undef __memset

#ifndef MEMSET
#define MEMSET __memset
#endif

void *__memset(void *dest, const int c, size_t n) {
	unsigned char *ptr = dest;
	while (n-- > 0)
		*ptr++ = c;
	return dest;
}

weak_alias(__memset, memset)