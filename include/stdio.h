#ifndef _STDIO_H
#define _STDIO_H 1
#include <stdarg.h>

#define __need_size_t
#define __need_NULL
#include <stddef.h>

#define EOF (-1)

struct _IO_FILE;
typedef struct _IO_FILE FILE;

#define SEEK_SET 0


#ifdef __cplusplus
extern "C" {
#endif


extern FILE* stderr;
#define stderr stderr
int fclose(FILE *);
extern int fflush(FILE *stream);
FILE *fopen(const char*, const char*);
extern int fprintf(FILE *f, const char *fmt, ...);
size_t fread(void*, size_t, size_t, FILE*);
int fseek(FILE*, long, int);
long ftell(FILE*);
size_t fwrite(const void*, size_t, size_t, FILE*);
void setbuf(FILE*, char*);
int vfprintf(FILE*, const char*, va_list);


#ifdef __cplusplus
}
#endif


#endif