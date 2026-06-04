#include <stddef.h>
#include <string.h>

#undef strtok

#ifndef STRTOK
# define STRTOK strtok
#endif

char	*STRTOK(char *__s, const char *__delim)
{
	return 0;
}

weak_alias(__strtok, strtok)
libc_hidden_builtin_def(strtok)
