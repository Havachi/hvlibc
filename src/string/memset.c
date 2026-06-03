#include <string.h>

void *memset(void *dest, const int c, size_t n) {
	unsigned char *ptr = dest;
	while (n-- > 0)
		*ptr++ = c;
	return dest;
}