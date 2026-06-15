#include <stdio.h>
#include <libhvio.h>

int fgetc(FILE *stream) {
	if (!stream) return EOF;
	
	if(stream->read_ptr >= stream->read_end) {
		if (_file_underflow(stream) == EOF) {
			return EOF;
		}
	}

	unsigned char c = (unsigned char) *stream->read_ptr++;
	return c;
}

int getchar(void) {
	return fgetc(stdin);
}