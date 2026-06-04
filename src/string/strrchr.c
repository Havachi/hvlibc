#include <stddef.h>
#include <string.h>

#undef strrchr

#ifndef STRRCHR
# define STRRCHR strrchr
#endif

char	*STRRCHR(const char *__s, int __c)
{
	return 0;
}

weak_alias(__strrchr, strrchr)
libc_hidden_builtin_def(strrchr)
