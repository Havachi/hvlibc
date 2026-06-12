#include <string.h>

#undef strcpy

#ifndef STRCPY
#define STRCPY strcpy
#endif

char    *STRCPY(char *dest, const char *src) {
	return memcpy(dest, src, strlen(src) + 1);
}

libc_hidden_builtin_def(strcpy);