#include <stddef.h>
#include <string.h>

#undef strspn

#ifndef STRSPN
# define STRSPN strspn
#endif

size_t	*STRSPN(const char *__s, const char *__accept)
{
	return 0;
}

weak_alias(__strspn, strspn)
libc_hidden_builtin_def(strspn)
