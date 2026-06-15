#include <stdio.h>
#include <stdlib.h>
#include <sysdep.h>


void exit(int exit_code) {
	fflush(stdout);
	fflush(stderr);

	__syscall1(SC_EXIT, exit_code);

	abort();
}