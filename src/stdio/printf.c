#include <stdio.h>

FILE *stderr = NULL;

int printf(const char *restrict format, ...) {
	return 0;
}

int fprintf(FILE *restrict stream, const char *restrict format, ...) {
	return 0;
}

int sprintf(char *restrict s, const char *restrict format, ...) {
	return 0;
}