

#include <sys/types.h>
#include <stdlib.h>
#include <sysdep.h>

pid_t waitpid(pid_t pid){
	return __syscall5(SC_WAITID, 0, pid, NULL, 0, NULL);
}