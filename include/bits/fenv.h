#ifndef _FENV_H
# error "Never use <bits/fenv.h> directly; include <fenv.h> instead."
#endif

#define FE_ALL_EXCEPT 0

typedef unsigned int fexcept_t;
typedef struct {
	fexcept_t __excepts;
} fenv_t;