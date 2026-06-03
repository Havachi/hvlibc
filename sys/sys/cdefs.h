#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_ 1

#ifndef _FEATURES_H
#include <features.h>
#endif


#undef	__P
#undef	__PMT


#define __P(protos) protos
#define __CONCAT(x,y) x ## y
#define __STRING(x) #x
#define __ptr_t void *

#define __const const
#define __signed signed
#define __volatile volatile
#define __inline inline

#define __dead		__attribute__((__noreturn__))

#define	__pure		__attribute__((__pure__))

#define	__unused	__attribute__((__unused__))
#define	__used		__attribute__((__used__))
#define __warn_unused_result	__attribute__((__warn_unused_result__))
#define __bounded(args)			__attribute__ ((__bounded__ args ))
#define __returns_twice	__attribute__((returns_twice))
#define __only_inline	extern __inline __attribute__((__gnu_inline__))
#define __predict_true(exp)	__builtin_expect(((exp) != 0), 1)
#define __predict_false(exp)	__builtin_expect(((exp) != 0), 0)

#define	__packed	__attribute__((__packed__))
#define	__aligned(x)	__attribute__((__aligned__(x)))
#define	__malloc	__attribute__((__malloc__))

#ifdef	__cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#define __THROW
#define __THROWNL
#define __NTH(fct)	fct
#define __NTHNL(fct) fct

#endif