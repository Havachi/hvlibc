#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <libhvio.h>
#include <stdbool.h>
#include <string.h>



static int _file_putc(int c, FILE *stream) {
	if (!stream) return EOF;
	if (stream->write_ptr >= stream->write_end) {
		if (_file_flush(stream) == EOF) return EOF;
	}
	*stream->write_ptr++ = (char)c;

	if ((stream->_flags & _IOLBF) && c == '\n') {
		if (_file_flush(stream) == EOF) return EOF;
	}
	if ((stream->_flags & _IONBF)) {
		if (_file_flush(stream) == EOF) return EOF;
	}
	return c;
}

static int _print_padding(FILE *stream, int n, char c) {
	for (int i = 0; i < n; i++){
		if (_file_putc(c, stream) == EOF) return -1;
	}
	return n;
}

static int _print_number(FILE *stream, unsigned long long value, int base, bool is_upper, int pad_len, char pad_char) {
	char buffer[64];
	int i = 0;
	int printed = 0;
	static const char HEX_DIGIT_LOWER[] = "0123456789abcdef";
	static const char HEX_DIGIT_UPPER[] = "0123456789ABCDEF";
	if (value == 0) {
		if (_file_putc('0', stream) == EOF) return -1;
		return 1;
	}

	while (value > 0) {
		if (is_upper) {
			buffer[i++] = HEX_DIGIT_UPPER[value % base];
		} else {
			buffer[i++] = HEX_DIGIT_LOWER[value % base];
		}
		value /= base;
	}
	_print_padding(stream, (pad_len-i), pad_char);

	for (int j = i - 1; j >= 0; j--) {
		if (_file_putc(buffer[j], stream) == EOF) return -1;
		printed++;
	}
	return printed;
}

int printf(const char *restrict format, ...) {
	va_list args;
	va_start(args, format);
	int printed = vfprintf(stdout, format, args);
	va_end(args);
	return printed;
}

int fprintf(FILE *restrict stream, const char *restrict format, ...) {
	va_list args;
	va_start(args, format);
	int printed = vfprintf(stream, format, args);
	va_end(args);
	return printed;
}

int sprintf(char *restrict s, const char *restrict format, ...) {
	return 0;
}

int vprintf(const char *restrict format, va_list arg) {
	return vfprintf(stdout, format, arg);
}


int vfprintf(FILE *restrict s, const char *restrict format, va_list arg) {
	int total = 0;

	for (const char *p = format; *p != '\0'; p++) {

		char pad_char = ' ';
		int pad_len = 0;

		if (*p != '%') {
			if (_file_putc(*p, s) == EOF) return -1;
			total++;
			continue;
		}
		p++;

		while (*p == 'l')
			p++;
		if(*p == '0') {
			pad_char = '0';
			p++;
		}
		while (isdigit(*p)) {
			pad_len = pad_len * 10 + (*p - '0');
			p++;
		}

		switch (*p) {
			case '%': {
				if (_file_putc('%', s) == EOF) return -1;
				total++;
				break;
			}
			case 'c': {
				char c = (char)va_arg(arg, int);
				if (_file_putc(c, s) == EOF) return -1;
				total++;
				break;
			}
			case 's': {
				const char *str = va_arg(arg, const char *);
				if (!str) str = "(null)";
				while(*str) {
					if (_file_putc(*str, s) == EOF) return -1;
					str++;
					total++;
				}
				break;
			}
			case 'd': 
			case 'i': {
				long long n = va_arg(arg, int);
				if (n < 0) {
					if (_file_putc('-', s) == EOF) return -1;
					total++;
					n = -n;
				}
				int printed = _print_number(s, (unsigned long long) n, 10, false, pad_len, pad_char);
				if (printed < 0) return -1;
				total += printed;
				break;
			}
			case 'u': {
				unsigned int n = va_arg(arg, unsigned int);
				int printed = _print_number(s, n, 10, false, pad_len, pad_char);
				if (printed < 0) return -1;
				total += printed;
				break;
			}
			case 'x': {
				unsigned int n = va_arg(arg, unsigned int);
				int printed = _print_number(s, n, 16, false, pad_len, pad_char);
				if (printed < 0) return -1;
				total += printed;
				break;
			}
			case 'X': {
				unsigned int n = va_arg(arg, unsigned int);
				int printed = _print_number(s, n, 16, true, pad_len, pad_char);
				if (printed < 0) return -1;
				total += printed;
				break;
			}
			case 'p': {
				
				void *ptr = va_arg(arg, void*);
				if (_file_putc('0', s) == EOF || _file_putc('x', s) == EOF) return -1;
				total += 2;
				int printed = _print_number(s, (unsigned long long)ptr, 16, false, pad_len, pad_char);
				if (printed < 0) return -1;
				total += printed;
				break;
			}
			default: {
				if (_file_putc('%', s) == EOF || _file_putc(*p, s)) return -1;
				total += 2;
				break;
			}
		}
	}
	return total;
}