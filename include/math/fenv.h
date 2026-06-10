#ifndef _FENV_H
#define _FENV_H 1

#define __HVLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>

#include <bits/fenv.h>

extern int feclearexcept(int __excepts);
extern int fegetexceptflag (fexcept_t *__flagp, int __excepts);
extern int feraiseexcept (int __excepts);

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fesetexcept(int __except);
#endif

extern int fesetexceptflag(const fexcept_t *__flagp, int __excepts);
extern int fetestexcept (int __excepts);

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fetestexceptflag (const fexcept_t *__flagp, int __excepts)
#endif

extern int fegetround(void) __attribute_pure__;
extern int fesetround (int __rounding_direction);
extern int fegetenv (fenv_t *__envp);
extern int feholdexcept (fenv_t *__envp);
extern int fesetenv (const fenv_t *__envp);
extern int feupdateenv (const fenv_t *__envp);

#if __HVLIBC_USE (IEC_60559_BFP_EXT_C23)
extern int fegetmode (femode_t *__modep);
extern int fesetmode (const femode_t *__modep);
#endif

#endif