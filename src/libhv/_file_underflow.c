#include <libhvio.h>
#include <syscall.h>

int _file_underflow(FILE *stream) {
	size_t buf_size = stream->buf_end - stream->buf_base;

	long bytes_read = _io_read(stream->fd, stream->buf_base, buf_size);
	if (bytes_read <= 0) {
		return EOF;
	}

	stream->read_base = stream->read_base;
	stream->read_ptr = stream->read_base;
	stream->read_end = stream->read_base + bytes_read;
	return (unsigned char) *stream->read_ptr;
}