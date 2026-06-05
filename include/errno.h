#ifndef _ERRNO_H
#define _ERRNO_H

#include <features.h>

#ifndef __ASSEMBLER__
extern int *__errno_location (void) __attribute_const__;
#define errno (*__errno_location ())
#endif
#endif