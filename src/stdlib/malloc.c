#include <stdlib.h>
#include <syscall-ids.h>
#include <stdint.h>



void *user_alloc_page(uint32_t pages) {
	uint64_t addr;
	__asm__ volatile("syscall" : "=a"(addr) : "a"(SC_MMAP), "S"(pages): "memory");
	return (void *) addr;
}

void user_free_pages(void *ptr, uint32_t pages) {
	int res;
	__asm__ volatile("syscall" : "=a"(res) : "a"(SC_MUNMAP), "D"(ptr), "S"(pages): "memory");
}


