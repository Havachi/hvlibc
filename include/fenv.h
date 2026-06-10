#ifndef _FENV_H
#include <math/fenv.h>
#include <sys/cdefs.h>

#include <bits/fenv.h>
#define __STDC_VERSION_FENV_H__ 201112L



__BEGIN_DECLS

extern int __feclearexcept(int __excepts);
extern int __fegetexcept(void);
extern int __fegetexceptflag(fexcept_t *__flagp, int __excepts);
extern int __feraiseexcept(int __excepts);
extern int __fesetexceptflag(const fexcept_t *__flagp, int __excepts);

extern int __fegetenv(fenv_t *__envp);
extern int __fesetenv(const fenv_t *__envp);
extern int __feupdateenv(const fenv_t* __envp);

extern __typeof (fegetround) __fegetround __attribute_pure__;
extern __typeof (feholdexcept) __feholdexcept;
extern __typeof (fesetround) __fesetround;
extern __typeof (fetestexcept) __fetestexcept;



#ifndef FE_TONEAREST
# error "FE_TONEAREST not defined
#endif 
#if defined FE_DOWNWARD ||	defined FE_TOWARDZERO || defined FE_UPWARD
# define FE_HAVE_ROUNDING_MODES 1
#else
# define FE_HAVE_ROUNDING_MODES 0
#endif

#if FE_ALL_EXCEPT == 0
# define feraiseexcept(excepts) ((void) 0)
# define __feraiseexcept(excepts) ((void) 0)
#endif

#if !FE_HAVE_ROUNDING_MODES
# if FE_ALL_EXCEPT == 0
extern inline int fegetenv(fenv_t *__e){
	return 0;
}
extern inline int __fegetenv (fenv_t *__e)
{
  return 0;
}

extern inline int feholdexcept (fenv_t *__e)
{
  return 0;
}

extern inline int __feholdexcept (fenv_t *__e)
{
  return 0;
}

extern inline int fesetenv (const fenv_t *__e)
{
  return 0;
}

extern inline int __fesetenv (const fenv_t *__e)
{
  return 0;
}

extern inline int feupdateenv (const fenv_t *__e)
{
  return 0;
}

extern inline int __feupdateenv (const fenv_t *__e)
{
  return 0;
}
# endif



extern inline int fegetround (void)
{
  return FE_TONEAREST;
}

extern inline int __fegetround (void)
{
  return FE_TONEAREST;
}

extern inline int fesetround (int __d)
{
  return 0;
}

extern inline int __fesetround (int __d)
{
  return 0;
}

# endif 
__END_DECLS
#endif