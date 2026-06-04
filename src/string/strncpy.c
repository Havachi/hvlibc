#include <stddef.h>
#include <string.h>

#undef strncpy

#ifndef STRNCPY
# define STRNCPY strncpy
#endif

char	*STRNCPY(char *__dest, const char *__src, size_t __n)
{
	return 0;
}

weak_alias(__strncpy, strncpy)
libc_hidden_builtin_def(strncpy)
