#include <stdlib.h>

void abort(void) {
	while(1)
		ABORT_INSTRUCTION;
}