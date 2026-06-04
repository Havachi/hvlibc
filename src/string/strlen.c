#include <stddef.h>
#include <string.h>

#undef strlen

#ifndef STRLEN
# define STRLEN strlen
#endif

size_t	*STRLEN(const char *__s)
{
	return 0;
}

weak_alias(__strlen, strlen)
libc_hidden_builtin_def(strlen)
