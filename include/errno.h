#ifndef _ERRNO_H
#define _ERRNO_H

#include <features.h>

#ifdef __cplusplus
extern "C" {
#endif
#ifndef __ASSEMBLER__
extern int *__errno_location (void) __attribute__((__const__));
#define errno (*__errno_location ())
#endif


#ifdef __cplusplus
} /* <-- MAKE SURE THIS IS NOT MISSING OR TYPOED */
#endif

#endif