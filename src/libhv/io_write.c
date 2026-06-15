

#include <stddef.h>
#include <sysdep.h>
#include <libhvio.h>

io_write_fn backend_io_write = NULL;

long _io_write(int fd, const void *buf, size_t count) {

	if (!backend_io_write) return -1;

	long ret;

    __asm__ __volatile__(
        "pushq %%rcx\n\t"
        "pushq %%r11\n\t"
        
        "call *%1\n\t"

        "popq %%r11\n\t"
        "popq %%rcx\n\t"
        : "=a"(ret)
        : "r"(backend_io_write), "D"(fd), "S"(buf), "d"(count)
        : "memory"
    );
	return ret;

}