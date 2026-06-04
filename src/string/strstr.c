#include <stddef.h>
#include <string.h>

#undef strstr

#ifndef STRSTR
# define STRSTR strstr
#endif

char	*STRSTR(const char *__haystack, const char *__needle)
{
	return 0;
}

weak_alias(__strstr, strstr)
libc_hidden_builtin_def(strstr)
