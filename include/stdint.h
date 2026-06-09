#ifndef _STDINT_H
#define _STDINT_H

#include <sys/types.h>
#include "bits/wordsize.h"

#if __WORDSIZE == 64
#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
#endif
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

typedef __intptr_t intptr_t;
typedef __uintptr_t uintptr_t;

#endif