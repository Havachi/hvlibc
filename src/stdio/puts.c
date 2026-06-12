#include <stdio.h>

int puts(const char *restrict s) {
	int r = 1;
	for (const char *c = s; *c != '\0'; c++) {
		putchar((int)*c);
		r++;
	}
	if (r == 1)
		return EOF;
	putchar('\n');
	return r;
}