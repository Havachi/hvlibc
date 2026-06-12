#include <stddef.h>
#include <syscall-ids.h>

extern long sys_write(int fd, char *buf, size_t count);