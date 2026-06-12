#include <libhvio.h>
#include <stdio.h>
#include <stdlib.h>
#include <hvosio.h>


FILE *__fopen_internal(const char *filename, const char *mode) {

	FILE *new_f = malloc(sizeof(FILE)); 
	new_f->_flags |= (_IO_MAGIC | _IO_ISFILE);
	hv_fopen(new_f, filename, mode);
}


FILE *fopen(const char *restrict filename, const char *restrict mode) {
	return __fopen_internal(filename, mode);
}