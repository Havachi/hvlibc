

#include <stddef.h>
#include <stdint.h>
#include <sysdep.h>
#include <libhvio.h>


long _io_write(int fd, const void *buf, size_t count) {
#if defined (__KERNEL__)
	extern long console_write(void *file, const char *buf, size_t count, uint64_t *offset);

	if (fd == 1 || fd == 2) {
		uint64_t dummy = 0;
		return console_write(NULL, (const char *)buf, count, &dummy);
	}
	return -1;
#else
	return __syscall3(SC_WRITE, fd, (long)buf, count);
#endif
}