#include <string.h>

#undef __memmove
#undef memmove

#ifndef MEMMOVE
#define MEMMOVE  __memmove
#endif

void *__memmove(void *dest, const void *src, size_t len) {
	char *d = dest;
	const char *s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else {
		const char *lasts = s + (len - 1);
		char *lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return dest;
}

weak_alias(__memmove, memmove)