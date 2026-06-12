#ifndef ____fpos_t_defined
#define ____fpos_t_defined 1

#include <bits/stdio/__mbstate.h>

typedef struct {
	long __pos;
	__mbstate_t mbstate;
} __fpos_t;


#endif