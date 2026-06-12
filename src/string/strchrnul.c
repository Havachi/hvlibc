#include <string.h>
#include <stdlib.h>

#undef __strchrnul
#undef strchrnul

#ifndef STRCHRNUL
# define STRCHRNUL __strchrnul
#endif

char *STRCHRNUL (const char *s, int c_in) {
	const unsigned char *char_ptr;
	const unsigned long int *longword_ptr;
	unsigned long int longword, magic_bits, charmask;
	unsigned char c;

	c = (unsigned char) c_in;

	for (char_ptr = (const unsigned char *)s;
		((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0;
		++char_ptr)
	{
		if (*char_ptr == c || *char_ptr == '\0'){
			return (void *) char_ptr;
		}
	}

	longword_ptr = (unsigned long int *) char_ptr;
	magic_bits = -1;
	magic_bits = magic_bits / 0xFF * 0xFE << 1 >> 1 | 1;

	charmask = c | (c << 8);
	charmask |= charmask << 16;
	if (sizeof(longword) > 4)
		charmask |= (charmask << 16) << 16;
	if (sizeof(longword) > 8)
		abort();

	//Black magic
	for (;;) {
		longword = *longword_ptr++;
		if ((((longword + magic_bits)
		 ^ ~longword)
		& ~magic_bits) != 0 ||
		((((longword ^ charmask) + magic_bits) ^ ~(longword ^ charmask))
		& ~magic_bits) != 0)
		{
			const unsigned char *cp = (const unsigned char *) (longword_ptr - 1);
			if (*cp == c || *cp == '\0')
				return (char *) cp;
			if (*++cp == c || *cp == '\0')
				return (char *) cp;
			if (*++cp == c || *cp == '\0')
				return (char *) cp;
			if (*++cp == c || *cp == '\0')
				return (char *) cp;
			if (sizeof(longword) > 4) {
				if (*++cp == c || *cp == '\0')
					return (char *) cp;
				if (*++cp == c || *cp == '\0')
					return (char *) cp;
				if (*++cp == c || *cp == '\0')
					return (char *) cp;
				if (*++cp == c || *cp == '\0')
					return (char *) cp;
			}
		}
	}
	return NULL;
}

weak_alias(__strchrnul, strchrnul)