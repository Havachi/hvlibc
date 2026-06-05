#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <string.h>

#include <stddef.h>


char	*__strtok_r(char *s, const char *delim, char **save_ptr)
{
	char *end;
	if (s == NULL)
		s = *save_ptr;
	if (*s == '\0') {
		*save_ptr = s;
		return NULL;
	}

	s += strspn(s, delim);
	if (*s == '\0') {
		*save_ptr = s;
		return NULL;
	}

	end = s + strcspn(s, delim);
	if (*end == '\0') {
		*save_ptr = end;
		return s;
	}
	*end = '\0';
	*save_ptr = end + 1;
	return s;
}
libc_hidden_def(__strtok_r)
weak_alias(__strtok_r, strtok_r)
