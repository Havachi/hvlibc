#include <stddef.h>
#include <string.h>

#undef strcspn

#ifndef STRCSPN
# define STRCSPN strcspn
#endif

size_t	*STRCSPN(const char *__s1, const char *__s2)
{
	return 0;
}

weak_alias(__strcspn, strcspn)
libc_hidden_builtin_def(strcspn)
