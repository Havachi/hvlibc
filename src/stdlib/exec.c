#include <sysdep.h>

int execve(const char *pathname, char *const argv[], char *const envp[]) {
	long ret = __syscall3(SC_EXECVE, pathname, argv, envp);
	return (int)ret;
}

int execv(const char *pathname, char *const argv[]) {
	long ret = __syscall2(SC_EXECVE, pathname, argv);
	return (int)ret;
}

int exec(const char *pathname) {
	long ret = __syscall1(SC_EXECVE, pathname);
	return (int)ret;
}