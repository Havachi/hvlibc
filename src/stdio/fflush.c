#include <stdio.h>
#include <libhvio.h>

int fflush(FILE *stream) {
	if (stream == NULL) {
		int r1 = _file_flush(stdout);
		int r2 = _file_flush(stderr);
		return (r1 == 0 && r2 == 0) ? 0 : EOF;
	}

	if (stream->write_base == NULL) {
		return 0;
	}

	return _file_flush(stream);
}