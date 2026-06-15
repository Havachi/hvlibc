#include <stdio.h>
#include <sysdep.h>
#include <libhvio.h>


size_t fwrite(const void *restrict ptr, size_t size, size_t n, FILE *restrict s) {
	size_t total = size * n;
	if (s->_flags & _IONBF) {
		return _io_write(s->fd, ptr, total);
	}

	return n;
}