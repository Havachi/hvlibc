#include <stddef.h>
#include <string.h>

#undef strerror

#ifndef STRERROR
# define STRERROR strerror
#endif

char	*STRERROR(int __e)
{
	return 0;
}

weak_alias(__strerror, strerror)
libc_hidden_builtin_def(strerror)
