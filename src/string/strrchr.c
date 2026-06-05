#include <stddef.h>
#include <string.h>

#undef strrchr

#ifndef STRRCHR
# define STRRCHR strrchr
#endif

char	*STRRCHR(const char *s, int c)
{
	const char *found, *p;
	c = (unsigned char) c;

	if (c == '\0')
		return strchr(s, '\0');
	found = NULL;

	while ((p = strchr(s, c)) != NULL){
		found = p;
		s = p + 1;
	}
	return (char *) found;
}

weak_alias(strrchr, rindex)
libc_hidden_builtin_def(strrchr)
