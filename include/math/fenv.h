#ifndef _FENV_H
#define _FENV_H 1

#define __HVLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>
#include <sys/cdefs.h>
#include <bits/fenv.h>

extern int feclearexcept(int __excepts) __THROW;
extern int fegetexceptflag (fexcept_t *__flagp, int __excepts) __THROW;
extern int feraiseexcept (int __excepts) __THROW;

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fesetexcept(int __except) __THROW;
#endif

extern int fesetexceptflag(const fexcept_t *__flagp, int __excepts) __THROW;
extern int fetestexcept (int __excepts) __THROW;

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fetestexceptflag (const fexcept_t *__flagp, int __excepts) __THROW;
#endif

extern int fegetround(void) __attribute_pure__;
extern int fesetround (int __rounding_direction) __THROW; 
extern int fegetenv (fenv_t *__envp) __THROW; 
extern int feholdexcept (fenv_t *__envp) __THROW; 
extern int fesetenv (const fenv_t *__envp) __THROW; 
extern int feupdateenv (const fenv_t *__envp) __THROW; 

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fegetmode (femode_t *__modep) __THROW; 
extern int fesetmode (const femode_t *__modep) __THROW; 
#endif

#if (__HVLIBC_USE(IEC_60559_BFP_EXT_C23) \
	&& defined FE_INVALID \
	&& defined __SUPPORT_SNAN__)
#define FE_SNANS_ALWAYS_SIGNAL 1
#endif

#ifdef __USE_GNU
extern int feenableexcept (int __excepts) __THROW;
extern int fedisableexcept (int __excepts) __THROW;
extern int fegetexcept (void) __THROW;
#endif

#endif