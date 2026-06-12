#ifndef __STRUCT_IO_FILE_
#define __STRUCT_IO_FILE_ 1

struct _IO_FILE {
	int fd;
	int _flags;
	char *read_ptr;
	char *read_end;
	char *read_base;
	char *write_ptr;
	char *write_end;
	char *write_base;
	char *buf_base;
	char *buf_end;
};

#endif