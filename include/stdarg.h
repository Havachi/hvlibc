#ifndef _STDARGS_H
#define _STDARGS_H

#include <sys/cdefs.h>
__BEGIN_DECLS
#ifdef __need___va_list
typedef __builtin_va_list va_list;
#endif


#define va_arg(ap, type)		(__builtint_va_arg(ap, type))
#define va_copy(dest, src)		(__builtin_va_copy(dest, src))
#define va_end(ap)				(__builtin_va_end(ap))
#define va_start(ap, parmN)		(__builtin_va_start(ap, parmN))

#define _VA_LIST_DEFINED
__END_DECLS

#endif