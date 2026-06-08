#include <stdlib.h>

extern void *user_alloc_page(uint32_t pages);
extern void user_free_pages(void *ptr, uint32_t pages);


int liballoc_lock() {
	return 0;
}

int liballoc_unlock() {
	return 0;
}

void* liballoc_alloc(int size) {
	return (void *)user_alloc_page(size);
}

int liballoc_free(void* ptr ,int size) {
	user_free_pages(ptr, size);
	return 0;
}

