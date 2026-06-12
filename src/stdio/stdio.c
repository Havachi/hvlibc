#include <stdio.h>
#include <libhvio.h>



static char stdout_buffer[BUFSIZ];

static FILE _stdin = { .fd = 0, ._flags = _IONBF };
static FILE _stderr = { .fd = 2, ._flags = _IONBF };
static FILE _stdout = {
	.fd = 1,
	._flags = _IONBF,
	.buf_base = stdout_buffer,
	.buf_end = stdout_buffer + BUFSIZ,
	.write_base = stdout_buffer,
	.write_ptr = stdout_buffer,
	.write_end = stdout_buffer + BUFSIZ,
};

FILE *stdin = &_stdin;
FILE *stdout = &_stdout;
FILE *stderr = &_stderr;


