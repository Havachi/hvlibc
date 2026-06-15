
#include <stddef.h>
#include <sysdep.h>

long _io_read(int fd, void *buf, size_t count) {
	return (long)__syscall3(SC_READ, fd, buf, count);
}