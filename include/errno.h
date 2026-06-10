#ifndef _ERRNO_H
#define _ERRNO_H

#include <features.h>
#include <sys/cdefs.h>
#include "errno-list.h"

__BEGIN_DECLS

#define errno (*__errno_location ())

extern int *__errno_location(void) __attribute_const__;

__END_DECLS

#endif