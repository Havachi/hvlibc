#ifndef _HVOSIO_H
#define _HVOSIO_H

//This header is made to connect hvlibc to hvos IO
//Probably won't work anywhere else
#include <stdio.h>
#ifndef __hvos__
# error "This header was made for HVOS, never include it anywhere else"
#endif

extern FILE *hv_fopen(FILE *fp, const char *restrict filename, const char *restrict mode);



#endif