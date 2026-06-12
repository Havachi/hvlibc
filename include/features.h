#ifndef _FEATURES_H
#define _FEATURES_H


#undef	__USE_ISOC11


#define __HVLIBC_USE(F)	__HVLIBC_USE_ ## F




#if defined __GNUC__ && defined __GNUC_MINOR__
# define __GNUC_PREREQ(maj, min) \
	((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) <<  16) + (min))
#else
# define __GNUC_PREREQ(maj, min) 0
#endif

#if defined __clang_major__ && defined __clang_minor__
# define __glibc_clang_prereq(maj, min) \
  ((__clang_major__ << 16) + __clang_minor__ >= ((maj) << 16) + (min))
#else
# define __glibc_clang_prereq(maj, min) 0
#endif

#ifdef __cplusplus
# if __cplusplus >= 201703L
#  define __USE_ISOC11 1
# endif

#endif




#endif