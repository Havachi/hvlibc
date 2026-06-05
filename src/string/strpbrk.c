#include <string.h>

#undef strpbrk

#ifndef STRPBRK
# define STRPBRK strpbrk
#endif

char	*STRPBRK(const char *s, const char *accept)
{
	s += strcspn(s, accept);
	return *s ? (char *)s : NULL;
}

libc_hidden_builtin_def(strpbrk)
