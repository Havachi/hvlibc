
#include <syscall-ids.h>
int open(const char *file) {
	int fd;
	__asm__ volatile(
		"syscall"
		: "=a"(fd)
		: "a"(SC_OPEN), "D"(file)
		: "rcx", "r11", "memory"
	);
}