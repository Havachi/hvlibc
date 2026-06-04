#include <stddef.h>
#include <string.h>

#undef strpbrk

#ifndef STRPBRK
# define STRPBRK strpbrk
#endif

char	*STRPBRK(const char *__s, const char *__accept)
{
	return 0;
}

weak_alias(__strpbrk, strpbrk)
libc_hidden_builtin_def(strpbrk)
