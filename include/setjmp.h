#ifndef _SETJMP_H
#define _SETJMP_H 1

#define __STDC_VERSION_SETJUMP_H__ 201112L

typedef int jmp_buf[1];
#define setjmp(env)

extern void longjmp(jmp_buf __env, int __val) \
		__attribute__ ((noreturn));

#endif