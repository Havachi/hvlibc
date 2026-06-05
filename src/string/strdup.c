#include <stdlib.h>
#include <string.h>

#undef __strdup
#undef strdup

#ifndef STRDUP
# define STRDUP strdup
#endif

extern void *malloc(size_t);

char	*__strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	void *new = malloc(len);

	if (new == NULL)
		return NULL;
	return (char *) memcpy(new, s, len);
}

libc_hidden_builtin_def(__strdup)
weak_alias(__strdup, strdup)
