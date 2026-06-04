#ifndef _HVLIBC_STDLIB_H
#define _HVLIBC_STDLIB_H 1

#include <sys/cdefs.h>
#include <sys/_null.h>
#include <machine/_types.h>


#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

#define ABORT_INSTRUCTION asm ("hlt")


void abort(void);



#endif