#ifndef _STDDEF_H_
#define _STDDEF_H_ 1

#include <sys/cdefs.h>
#include <sys/_types.h>
#include <sys/_null.h>
#include <libc-symbols.h>
#ifndef __PTRDIFF_T_DEFINED_
#define __PTRDIFF_T_DEFINED_
typedef __ptrdiff_t ptrdiff_t;
#endif

#ifndef	_SIZE_T_DEFINED_
#define	_SIZE_T_DEFINED_
#define _HAVE_SIZE_T
typedef	__size_t	size_t;
#endif

#if !defined(_WCHAR_T_DEFINED_) && !defined(__cplusplus)
#define _WCHAR_T_DEFINED_
typedef	__wchar_t	wchar_t;
#endif

#ifndef	_WINT_T_DEFINED_
#define	_WINT_T_DEFINED_
typedef	__wint_t	wint_t;
#endif

#ifndef _MAX_ALIGN_T_DEFINED
#define _MAX_ALIGN_T_DEFINED
typedef struct {
	long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
	long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
#endif

#ifndef NULL
#define NULL ((void)0) 
#endif

#ifndef offsetof
#define offsetof(type, membr) ((size_t) &(((type *)0)->member))
#endif

#endif