#include <stdio.h>
#include <libhvio.h>



static char stdin_buffer[BUFSIZ];

static FILE _stdin = {
	.fd = 0,
	._flags = _IOLBF,
	.buf_base = stdin_buffer,
	.buf_end = stdin_buffer + BUFSIZ,
	.read_base = stdin_buffer,
	.read_ptr = stdin_buffer,
	.read_end = stdin_buffer,

	.write_base = NULL,
	.write_ptr = NULL,
	.write_end = NULL,
};



static FILE _stderr = {
	.fd = 2,
	._flags = _IONBF,

	.buf_base = NULL,
	.buf_end = NULL,
	.write_base = NULL,
	.write_ptr = NULL,
	.write_end = NULL,
	.read_base = NULL,
	.read_ptr = NULL,
	.read_end = NULL,
};

FILE *stdin = &_stdin;
//FILE *stdout = &_stdout;
FILE *stderr = &_stderr;

