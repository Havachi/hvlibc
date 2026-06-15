#ifndef _STDLIB_H
#define _STDLIB_H 1

#include <stddef.h>
#include <sys/cdefs.h>
#include <sys/_null.h>
#include <liballoc.h>

#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

#define ABORT_INSTRUCTION __asm__ ("hlt")

__BEGIN_DECLS

void abort(void);
void atexit(void (*)(void));
void exit(int exit_code);
void atoi(const char *);
void getenv(const char *);

extern void *malloc(size_t size);
extern void *calloc(size_t size, size_t n);
extern void *realloc(size_t size, size_t n);
extern void free(void *);


int execve(const char *pathname, char *const argv[], char *const envp[]);
int execv(const char *pathname, char *const argv[]);
int exec(const char *pathname);

__END_DECLS

#endif