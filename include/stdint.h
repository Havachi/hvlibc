#ifndef _STDINT_H
#define _STDINT_H

#include <sys/_types.h>
#include "bits/wordsize.h"

#if __WORDSIZE == 64
# ifndef __intptr_t_defined
typedef long int intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned long int uintptr_t;
#else
# ifndef __intptr_t_defined
typedef int intptr_t;
#  define __intptr_t_defined
# endif
typedef unsigned int uintptr_t;
#endif

# if __WORDSIZE == 64
#  define SIZE_MAX		(18446744073709551615UL)
# else
#  if __WORDSIZE32_SIZE_ULONG
#   define SIZE_MAX		(4294967295UL)
#  else
#   define SIZE_MAX		(4294967295U)
#  endif
# endif

typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;

#endif