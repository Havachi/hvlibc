
#include <stddef.h>
#include <sysdep.h>

long _io_open(const char *path, int flags) {
	int fd = 0;
	fd = __syscall2(SC_OPEN, path, flags);
	return fd;
}