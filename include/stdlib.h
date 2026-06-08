#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <stddef.h>
#include <sys/cdefs.h>
#include <sys/_null.h>
#include <machine/_types.h>


#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

#define ABORT_INSTRUCTION __asm__ ("hlt")

__BEGIN_DECLS

void abort(void);
void atexit(void (*)(void));
void atoi(const char *);
void free(void *);
void getenv(const char *);
void *malloc(size_t size);
void *calloc(size_t size, size_t n);

__END_DECLS

#endif