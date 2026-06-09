
#include <unistd.h>
#include <stdlib.h>

void _exit(int status) {
	status &= 0xFF;
	abort();
}

libc_hidden_def(_exit)
weak_alias(_exit, _Exit);
