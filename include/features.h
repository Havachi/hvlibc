#ifndef _FEATURES_H
#define _FEATURES_H

#define __HVLIBC_USE(F)	__HVLIBC_USE_ ## F

#ifndef __ASSEMBLER__
# ifndef _SYS_CDEFS_H
#  include <sys/cdefs.h>
# endif

#endif
#endif