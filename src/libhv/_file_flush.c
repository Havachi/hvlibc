#include <libhvio.h>
#include <syscall.h>

int _file_flush(FILE *stream) {
	if (!stream) return -1;
	size_t amount = stream->write_ptr - stream->write_base;
	if (amount > 0) {
		long written = _io_write(stream->fd, stream->write_base, amount);
		if (written < 0) return EOF;
		stream->write_ptr = stream->write_base;
	}
	return 0;
}