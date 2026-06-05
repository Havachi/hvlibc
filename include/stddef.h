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



#endif