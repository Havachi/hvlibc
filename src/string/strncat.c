#include <stddef.h>
#include <string.h>

#undef strncat

#ifndef STRNCAT
# define STRNCAT strncat
#endif

char	*STRNCAT(char *__dest, const char *__src, size_t __n)
{
	return 0;
}

weak_alias(__strncat, strncat)
libc_hidden_builtin_def(strncat)
