#include <stddef.h>
#include <string.h>

#undef strcat

#ifndef STRCAT
# define STRCAT strcat
#endif

char	*STRCAT(char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

libc_hidden_builtin_def(strcat)
