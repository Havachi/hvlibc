#include <stdio.h>
#include <syscall.h>

int putc(int c, FILE *stream) {
	char ch = (char)c;

	long written = sys_write(stream->fd, &ch, 1);

	if (written == 1)
		return c;
	else
		return EOF;
}

int putchar (int c) {
	return putc(c, stdout);
}