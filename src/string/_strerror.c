#include <stddef.h>
#include <string.h>

#undef strerror

#ifndef STRERROR
# define STRERROR strerror
#endif

char	*__strerror(int errnum)
{
	if (errnum)
		return NULL;
	return NULL;
}

weak_alias(__strerror, strerror)
libc_hidden_builtin_def(strerror)
