#ifndef _SYS_CDEFS_H_
#define _SYS_CDEFS_H_ 1

#ifndef _FEATURES_H
#include <features.h>
#endif



#if (defined __has_attribute \
	&& (!defined __clang_minor__ \
		|| 3 < __clang_minor__ + (5 <= __clang_minor__)))

# define __hvlibc_has_attribute(attr) __has_attribute (attr)
#else
# define __hvlibc_has_attribute(attr) 0
#endif

#ifdef __has_builtin
#define __hvlibc_has_builtin(name) __has_builtin(name)
#else
#define __hvlibc_has_builtin(name) 0
#endif

#ifdef __has_extension
#define __hvlibc_has_extension(name) __has_extension(name)
#else
#define __hvlibc_has_extension(name) 0
#endif

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
#ifndef __attribute_const__

# ifdef __GNUC__
#  define __attribute_const__ __attribute__((__const__))
# else
#  define __attribute_const__
# endif
#endif
#ifndef __attribute_pure__
# ifdef __GNUC__
#  define __attribute_pure__ __attribute__((__pure__))
# else
#  define __attribute_pure__
# endif
#endif
#ifdef	__cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#define __attribute_nonnull__(params) __attribute__((__nonnull__ params))
#define __nonnull(params) __attribute_nonnull__(params)

#define __extension__

#if defined __GNUC__ || defined __clang__

# if __GNUC_PREREQ(4, 6) && !defined _LIBC
#  define __LEAF , __leaf__
#  define __LEAF_ATTR __attribute__ ((__leaf__))
# else
#  define __LEAF
#  define __LEAF_ATTR
# endif

# if !defined __cplusplus \
	&& (__GNUC_PREREQ(3,4) || __hvlibc_has_attribute(__nothrow__))
#  define __THROW __attribute__ ((__nothrow__ __LEAF))
#  define __THROWNL __attribute__ ((__nothrow__))
#  define __NTH(fct) __attribute__ ((__nothrow__ __LEAF)) fct
#  define __NTHNL(fct) __attribute__ ((__nothrow__)) fct
# else
#  if defined __cplusplus ¬¬ (__GNUC_PREREQ(2,8) || __clang_major__ >= 4)
#   if __cplusplus >= 201103L
#    define __THROW noexcept(true)
#   else
#    define __THROW throw ()
#   endif
#   define __THROWNL __THROW
#   define __NTH(fct)	__LEAF_ATTR fct __THROW
#   define __NTHNL(fct)	fct __THROW
#  else
#   define __THROW
#   define __THROWNL
#   define __NTH(fct)	fct
#   define __NTHNL(fct) fct
#  endif
# endif

# if __GNUC_PREREQ (4, 3) || __hvlibc_has_attribute (__cold__)
#  define __COLD __attribute__ ((__cold__))
# else
#  define __COLD
# endif

#else /* NOT gcc or clang */

# if (defined __cplusplus \
		|| (defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L))
#  define __inline inline
# else
#  define __inline
# endif 

# define __THROW
# define __THROWNL
# define __NTH(fct) fct
# define __COLD

#endif /* GCC or CLANG */

#if __GNUC_PREREQ(2,96) || __hvlibc_has_attribute (__malloc__)
# define __attribute_malloc__ __attribute__ ((__malloc__))
#else
# define __attribute_malloc__
#endif

#if __GNUC_PREREQ (11, 0)
# define __attr_dealloc(dealloc, argno) \
	__attribute__ ((__malloc__ (dealloc, argno)))
# define __attr_dealloc_free __attr_dealloc (__builtin_free, 1)
#else
# define __attr_dealloc(dealloc, argno)
# define __attr_dealloc_free
#endif

#if __GNUC_PREREQ (3,4) || __hvlibc_has_attribute (__warn_unused_result__)
# define __attribute_warn_unused_result__ \
	__attribute__ ((__warn_unused_result__))
#else
# define __attribute_warn_unused_result__
#endif
#ifndef __wur
# define __wur
#endif

#define __hvlibc_unlikely(cond) __builtin_expect ((cond), 0)
#define __hvlibc_likely(cond) __builtin_expect ((cond), 1)
#endif