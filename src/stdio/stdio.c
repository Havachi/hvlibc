#include <stdio.h>
#include <libhvio.h>



static char stdout_buffer[BUFSIZ];
static char stderr_buffer[BUFSIZ];
static char stdin_buffer[BUFSIZ];

static FILE _stdin = {
	.fd = 0,
	._flags = _IOFBF,
	.buf_base = stdin_buffer,
	.buf_end = stdin_buffer + BUFSIZ,
	.read_base = stdin_buffer,
	.read_ptr = stdin_buffer,
	.read_end = stdin_buffer,

	.write_base = NULL,
	.write_ptr = NULL,
	.write_end = NULL,
};

static FILE _stdout = {
	.fd = 1,
	._flags = _IONBF,
	.buf_base = stdout_buffer,
	.buf_end = stdout_buffer + BUFSIZ,
	.write_base = stdout_buffer,
	.write_ptr = stdout_buffer,
	.write_end = stdout_buffer + BUFSIZ,
	.read_base = NULL,
	.read_ptr = NULL,
	.read_end = NULL,
};

static FILE _stderr = {
	.fd = 2,
	._flags = _IONBF,
	.buf_base = stderr_buffer,
	.buf_end = stderr_buffer + BUFSIZ,
	.write_base = stderr_buffer,
	.write_ptr = stderr_buffer,
	.write_end = stderr_buffer + BUFSIZ,
	.read_base = NULL,
	.read_ptr = NULL,
	.read_end = NULL,
};

FILE *stdin = &_stdin;
FILE *stdout = &_stdout;
FILE *stderr = &_stderr;


