#ifndef _STDIO_H
#define _STDIO_H 1


#define __need_size_t
#define __need_NULL
#include <stddef.h>
#include <sys/cdefs.h>

#include <bits/stdio/IO_FILE.h>
#include <bits/stdio/__fpos_t.h>
#define __need___va_list
#include <stdarg.h>

#ifndef _VA_LIST_DEFINED
typedef __builtin_va_list va_list;
#endif
__BEGIN_DECLS



struct _IO_FILE;
/* Types */
typedef struct _IO_FILE FILE;
typedef __fpos_t fpos_t;

/* Predefined standard streams */
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

#define stdin stdin
#define stdout stdout
#define stderr stderr


/* Macro constants */
#define EOF (-1)

#define FOPEN_MAX 16

#define FILENAME_MAX 32

#define BUFSIZ 8192

/*fully buffered*/
#define _IOFBF 0x0008
/*Line-buffered*/
#define _IOLBF 0x0002
/*unbuffered*/
#define _IONBF 0x0004

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define TMP_MAX 238328
#define TMP_MAX_S 16

#define L_tmpnam	20
#define L_tmpnam_s	32

#define L_tmpnam (sizeof(char) * FILENAME_MAX)


extern int		remove(const char* __filename) __THROW;
extern int		rename(const char* __filename, const char* __new) __THROW;
extern int		fclose(FILE* __stream) __nonnull ((1));
#undef __attr_dealloc_fclose
#define __attr_dealloc_fclose __attr_dealloc (fclose, 1)



extern FILE*	tmpfile(void) __attribute_malloc__ __attr_dealloc_fclose __wur;
extern char*	tmpname(char[L_tmpnam]) __THROW __wur;
extern int		fflush(FILE* __stream);
extern FILE*	fopen(const char* __restrict __filename, const char* __restrict __mode)
	__attribute_malloc__ __attr_dealloc_fclose __wur;

extern FILE*	freopen(const char* __restrict __filename,
		const char* __restrict __mode,
		FILE* __restrict __stream) __wur __nonnull((3));

extern void		setbuf(FILE* __restrict __stream, char* __restrict __buf) __THROW __nonnull((1));
extern void		setvbuf(FILE* __restrict __stream, char* __restrict __buf,
			int __mode, size_t __size) __THROW __nonnull((1));

extern int		fprintf(FILE* __restrict __stream, const char *__restrict __format, ...) __nonnull((1));
extern int 		printf(const char* __restrict __format, ...);
extern int 		sprintf(char *__restrict __s, const char* __restrict __format, ...) __THROWNL;
extern int		vfprintf(FILE* __restrict __s, const char *__restrict __format,
		va_list __arg) __nonnull((1));

extern int 		vprintf(const char* __restrict __format, va_list __arg);
extern int 		vsprintf(char* __restrict __s, const char* __restrict __format, va_list __arg) __THROWNL;

extern int		snprintf(char *__restrict __s, size_t __maxlen,
			const char *__restrict __format, ...)
		__THROWNL __attribute__ ((__format__(__printf__, 3, 4)));
	
extern int		vsnprintf(char *__restrict __s, size_t __maxlen,
			const char *__restrict __format, ...)
		__THROWNL __attribute__ ((__format__ (__printf__, 3, 0)));

extern int fscanf(FILE* __restrict __stream,
		const char *__restrict __format, ...) __wur __nonnull((1));
extern int scanf(const char *__restrict __format, ...) __wur;
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) __THROW;

extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
		va_list __arg) 
	__attribute__ ((__format__ (__scanf__, 2, 0))) __wur __nonnull((1));

extern int vscanf (const char *__restrict __format, va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) __wur;

extern int vsscanf (const char *__restrict __s,
		    const char *__restrict __format, va_list __arg)
     __THROW __attribute__ ((__format__ (__scanf__, 2, 0)));

extern int fgetc (FILE *__stream) __nonnull ((1));
extern int getc (FILE *__stream) __nonnull ((1));
extern int getchar (void);

extern int fputc (int __c, FILE *__stream) __nonnull ((2));
extern int putc (int __c, FILE *__stream) __nonnull ((2));
extern int putchar (int __c);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     __wur __nonnull ((3));

extern int fputs (const char *__restrict __s, FILE *__restrict __stream)
  __nonnull ((2));
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream) __nonnull ((2));

extern size_t fwrite (const void *__restrict __ptr, size_t __size,
		      size_t __n, FILE *__restrict __s) __nonnull((4));

extern int fseek (FILE *__stream, long int __off, int __whence)
  __nonnull ((1));

extern long int ftell (FILE *__stream) __wur __nonnull ((1));
extern void rewind (FILE *__stream) __nonnull ((1));

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
  __nonnull ((1));
extern int fsetpos (FILE *__stream, const fpos_t *__pos) __nonnull ((1));
extern void clearerr (FILE *__stream) __THROW __nonnull ((1));
extern int feof (FILE *__stream) __THROW __wur __nonnull ((1));
extern int ferror (FILE *__stream) __THROW __wur __nonnull ((1));
extern void perror (const char *__s) __COLD;
__END_DECLS


#endif