

#include <stddef.h>
#include <sysdep.h>

long sys_write(int fd, char *buf, size_t count) {
	long written = 0;
	written = __syscall3(SC_WRITE, fd, buf, count);
	return written;
}