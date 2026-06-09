
#include <syscall-ids.h>
#include <stdint.h>

int write(int fd, const void* buf, uint32_t size) {
	int res; 
    __asm__ volatile("syscall" : "=a"(res) : "a"(SC_WRITE), "D"(fd), "S"(buf), "d"(size) : "rcx", "r11", "memory");
	return res;
}