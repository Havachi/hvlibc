#include <stddef.h>
#include <string.h>


#define RETURN_TYPE char *
#define AVAILABLE(h, h_l, j, n_l)			\
  (((j) + (n_l) <= (h_l)) || ((h_l) += __strnlen ((void*)((h) + (h_l)), 512), \
			      (j) + (n_l) <= (h_l)))
#define CHECK_EOL (1)
#define RET0_IF_0(a) if (!a) goto ret0
#define FASTSEARCH(S,C,N) (void*) strchr ((void*)(S), (C))
#include "str-two-way.h"


#undef strstr

#ifndef STRSTR
# define STRSTR strstr
#endif




char	*STRSTR(const char *haystack, const char *needle)
{
	size_t needle_len;
	size_t haystack_len;

	if (needle[0] == '\0')
		return (char *) haystack;
	haystack = strchr(haystack, needle[0]);
	if (haystack == NULL || needle[1] == '\0')
		return (char *) haystack;
	needle_len = strlen(needle);
	haystack_len = __strnlen(haystack, needle_len + 256);
	if (haystack_len < needle_len)
		return NULL;
	if (memcmp(haystack, needle, needle_len) == 0)
		return (char *) haystack;

	if(needle_len < LONG_NEEDLE_THRESHOLD)
		return two_way_short_needle(
			(const unsigned char *) haystack,
			haystack_len,
			(const unsigned char *) needle,
			needle_len
		);
	return two_way_long_needle(
			(const unsigned char *) haystack,
			haystack_len,
			(const unsigned char *) needle,
			needle_len
		);
}

libc_hidden_builtin_def(strstr)
