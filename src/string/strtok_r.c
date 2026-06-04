#include <stddef.h>
#include <string.h>

#undef strtok_r

#ifndef STRTOK_R
# define STRTOK_R strtok_r
#endif

char	*STRTOK_R(char *__s, const char *__delim, char **__save_ptr)
{
	return 0;
}

weak_alias(__strtok_r, strtok_r)
libc_hidden_builtin_def(strtok_r)
