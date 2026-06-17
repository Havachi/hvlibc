#ifndef _SIGNAL_H
#define _SIGNAL_H 1


typedef int sig_atomic_t;

#define SIGHUP	1
#define SIGINT  2
#define SIGQUIT 3
#define SIGILL	4
#define SIGTRAP	5

#define SIGABRT 6
#define SIGIOT	6
#define SIGBUS	7
#define SIGFPE	8
#define SIGKILL 9

#define SIGUSR1 10
#define SIGSEGV 11
#define SIGUSR2 12
#define SIGTERM 15

#define SIG_DFL 6
#define SIG_IGN 7

void (*signal(int sig, void (*func)(int)))(int);

int raise(int sig);

#endif