#include <stdio.h>
#include <libhvio.h>
#include <fcntl.h>


#ifdef __KERNEL__
static char kernel_stdin_buffer[BUFSIZ] __attribute__((aligned(16)));
static char kernel_stdout_buffer[BUFSIZ] __attribute__((aligned(16)));
static char kernel_stderr_buffer[BUFSIZ] __attribute__((aligned(16)));
#else
static char user_stdin_buffer[BUFSIZ] __attribute__((aligned(16)));
static char user_stdout_buffer[BUFSIZ] __attribute__((aligned(16)));
static char user_stderr_buffer[BUFSIZ] __attribute__((aligned(16)));
#endif


static FILE _stdin = {
	.fd = 0,
	._flags = _IONBF,
#ifdef __KERNEL__
	.buf_base = kernel_stdin_buffer,
	.buf_end = kernel_stdin_buffer + BUFSIZ,
	.read_base = kernel_stdin_buffer,
	.read_ptr = kernel_stdin_buffer,
	.read_end = kernel_stdin_buffer + BUFSIZ,
#else
	.buf_base = user_stdin_buffer,
	.buf_end = user_stdin_buffer + BUFSIZ,
	.read_base = user_stdin_buffer,
	.read_ptr = user_stdin_buffer,
	.read_end = user_stdin_buffer + BUFSIZ,
#endif
	.write_base = NULL, .write_ptr = NULL, .write_end = NULL
};


static FILE _stdout = {
	.fd = 1,
	#ifdef __KERNEL__
	._flags = _IONBF,
	.buf_base = kernel_stdout_buffer,
	.buf_end = kernel_stdout_buffer + BUFSIZ,
	.write_base = kernel_stdout_buffer,
	.write_ptr = kernel_stdout_buffer,
	.write_end = kernel_stdout_buffer + BUFSIZ,
#else
	._flags = _IONBF,
	.buf_base = user_stdout_buffer,
	.buf_end = user_stdout_buffer + BUFSIZ,
	.write_base = user_stdout_buffer,
	.write_ptr = user_stdout_buffer,
	.write_end = user_stdout_buffer + BUFSIZ,
#endif
	.read_base = NULL, .read_ptr = NULL, .read_end = NULL
};

static FILE _stderr = {
	.fd = 2,
	._flags = _IONBF,
#ifdef __KERNEL__
	.buf_base = kernel_stderr_buffer,
	.buf_end = kernel_stderr_buffer + BUFSIZ,
	.write_base = kernel_stderr_buffer,
	.write_ptr = kernel_stderr_buffer,
	.write_end = kernel_stderr_buffer + BUFSIZ,
#else
	.buf_base = user_stderr_buffer,
	.buf_end = user_stderr_buffer + BUFSIZ,
	.write_base = user_stderr_buffer,
	.write_ptr = user_stderr_buffer,
	.write_end = user_stderr_buffer + BUFSIZ,
#endif
	.read_base = NULL, .read_ptr = NULL, .read_end = NULL
};


FILE *stdin = &_stdin;
FILE *stdout = &_stdout;
FILE *stderr = &_stderr;