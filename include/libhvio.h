#include <stdio.h>
#include <sys/types.h>
#ifndef __LIBHVIO_H
#define __LIBHVIO_H 1

#define _IO_MAGIC			0x13370000
#define _IO_MAGIC_MASK		0xFFFF0000
#define _IO_USER_BUF			0x0001
#define _IO_UNBUFFERED			0x0002

#define _IO_NO_READS			0x0004
#define _IO_NO_WRITES			0x0008

#define _IO_ISFILE				0x2000

typedef long (*io_write_fn)(int fd, const char *buf, size_t count);


extern int _file_flush(FILE *stream);
extern int _file_underflow(FILE *stream);


extern long _io_read(int fd, void *buf, size_t count);
extern long _io_write(int fd, const void *buf, size_t count);
extern long _io_open(const char *path, int flags);

#endif