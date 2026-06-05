#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#undef strcoll

#ifndef STRING_TYPE
# define STRING_TYPE char
# define STRCOLL strcoll
# define STRCOLL_L __strcoll_l
# define USE_HIDDEN_DEF
#endif

//Not yet implemented
int	STRCOLL(const char *s1, const char *s2)
{
	abort();
	(void)s1;
	(void)s2;
	return 0;
}

#ifdef USE_HIDDEN_DEF
libc_hidden_def (STRCOLL)
#endif