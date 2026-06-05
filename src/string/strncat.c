#include <stddef.h>
#include <string.h>

#undef strncat

#ifndef STRNCAT
# undef strncat
# define STRNCAT strncat
# define STRNCAT_PRIMARY
#endif

char	*STRNCAT(char *s1, const char *s2, size_t n)
{
	char *s = s1;
	s1 += strlen(s1);

	size_t ss = __strnlen(s2, n);
	s1[ss] = '\0';
	memcpy(s1, s2, ss);
	return s;
}
#ifdef STRNCAT_PRIMARY
strong_alias(STRNCAT, __strncat);
libc_hidden_def(__strncat)
#endif
