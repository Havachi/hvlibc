#include <stdio.h>
#include <sysdep.h>


size_t fwrite(const void *restrict ptr, size_t size, size_t n, FILE *restrict s) {
	size_t total = size * n;
	if (s->_flags & _IONBF) {
		return __syscall3(SC_WRITE, s->fd, ptr, total);
	}

	return n;
}