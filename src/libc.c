#include <stdio.h>
#include <stddef.h>
#include <sysdep.h>

static char stdout_buffer[BUFSIZ]__attribute__((aligned(16)));

static FILE _stdout __attribute__((aligned(16)));

extern long (*backend_io_write)(int fd, const char *buf, size_t count);
static long user_sys_write_adapter(int fd, const char *buf, size_t count) {
	long ret;
	// Explicitly enforce SysV ABI registers for the syscall instruction
	__asm__ __volatile__(
		"syscall"
		: "=a"(ret)
		: "a"((long)1), "D"((long)fd), "S"((long)buf), "d"((long)count)
		: "rcx", "r11", "memory"
	);
	return ret;
}

void libc_init(void) {
	backend_io_write = user_sys_write_adapter;
	_stdout.fd = 1;
	_stdout._flags = _IOLBF;
	_stdout.buf_base = stdout_buffer;
	_stdout.buf_end = stdout_buffer + BUFSIZ;
	_stdout.write_base = stdout_buffer;
	_stdout.write_ptr = stdout_buffer;
	_stdout.write_end = stdout_buffer + BUFSIZ;

	_stdout.read_base = NULL;
	_stdout.read_ptr = NULL;
	_stdout.read_end = NULL;

	stdout = &_stdout;
}