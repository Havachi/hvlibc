#include <stdint.h>
char *itoa(int num, char* str, int radix) {
	char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int si = 0;
	int n = num;
	
	// Handle negative numbers for base 10
	if (n < 0 && radix == 10) {
		str[si++] = '-';
		n = -n;
	}
	// Convert number to string
	char tmp[33]; // Sufficient for 32-bit int + null
	int rdi = -1;
	while (n) {
		tmp[++rdi] = base[n % radix];
		n /= radix;
	}
	// Special case for 0
	if (rdi == -1) {
		tmp[++rdi] = '0';
	}
	// Reverse and add to buffer
	while (rdi >= 0) {
		str[si++] = tmp[rdi--];
	}
	str[si] = '\0'; // Null-terminate
	return str;
}

char *litoa(unsigned long num, char* str, int radix) {
	char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int si = 0;
	uint64_t n = num;
	
	// Handle negative numbers for base 10
	if (n < 0 && radix == 10) {
		str[si++] = '-';
		n = -n;
	}
	// Convert number to string
	char tmp[33]; // Sufficient for 32-bit int + null
	int rdi = -1;
	while (n) {
		tmp[++rdi] = base[n % radix];
		n /= radix;
	}
	// Special case for 0
	if (rdi == -1) {
		tmp[++rdi] = '0';
	}
	// Reverse and add to buffer
	while (rdi >= 0) {
		str[si++] = tmp[rdi--];
	}
	str[si] = '\0'; // Null-terminate
	return str;
}