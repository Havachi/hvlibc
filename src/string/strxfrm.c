#include <stddef.h>
#include <string.h>

#undef strxfrm

#ifndef STRXFRM
# define STRXFRM strxfrm
#endif

size_t	*STRXFRM(char *__dest, const char *__src, size_t __n)
{
	return 0;
}

weak_alias(__strxfrm, strxfrm)
libc_hidden_builtin_def(strxfrm)
