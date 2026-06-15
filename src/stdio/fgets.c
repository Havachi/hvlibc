#include <stdio.h>

char *fgets(char *restrict s, int n, FILE *restrict stream) {
	if (n <= 0 || !s || !stream) return  NULL;

	int i = 0;
	while (i < n - 1) {
		int c = fgetc(stream);
		if (c == EOF) {
			if (i == 0) return  NULL;
			break;
		}
		
		s[i++] = (char)c;
		if (c == '\n') {
			break;
		}
	}
	s[i] = '\0';
	return s;
}