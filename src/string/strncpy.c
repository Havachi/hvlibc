#include <string.h>

#undef strncpy

#ifndef STRNCPY
# define STRNCPY strncpy
#endif

char	*STRNCPY(char *s1, const char *s2, size_t n)
{
	size_t size = __strnlen(s2, n);
	if (size != n)
		memset(s1 + size, '\0', n - size);
	return memcpy(s1, s2, size);
}

libc_hidden_builtin_def(strncpy)
