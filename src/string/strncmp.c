#include <stddef.h>
#include <string.h>

#undef strncmp

#ifndef STRNCMP
# define STRNCMP strncmp
#endif

int	*STRNCMP(const char *__s1, const char *__s2, size_t __n)
{
	return 0;
}

weak_alias(__strncmp, strncmp)
libc_hidden_builtin_def(strncmp)
