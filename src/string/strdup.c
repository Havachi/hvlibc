#include <stddef.h>
#include <string.h>

#undef strdup

#ifndef STRDUP
# define STRDUP strdup
#endif

char	*STRDUP(const char *__s)
{
	return 0;
}

weak_alias(__strdup, strdup)
libc_hidden_builtin_def(strdup)
