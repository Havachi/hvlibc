#include <string.h>
#include <stdlib.h>

#ifdef STRNLEN
# define __strnlen STRNLEN
#endif

size_t __strnlen(const char *str, size_t maxlen) {
	const char *char_ptr, *end_ptr = str + maxlen;
	const unsigned long int *longword_ptr;
	unsigned long int longword, himagic, lomagic;

	if (maxlen == 0)
		return 0;

	if (__hvlibc_unlikely(end_ptr < str))
		end_ptr = (const char *) ~0UL;

	for (
		char_ptr = str;
		((unsigned long int) char_ptr & (sizeof(longword) - 1)) != 0;
		++char_ptr
	) {
		if (*char_ptr == '\0') {
			if (char_ptr > end_ptr)
				char_ptr = end_ptr;
			return char_ptr - str;
		}
	}
	longword_ptr = (unsigned long int *) char_ptr;
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof(longword) > 4) {
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	if (sizeof(longword) > 8)
		abort();

	while (longword_ptr < (unsigned long int *) end_ptr) {
		longword = *longword_ptr++;
		if ((longword - lomagic) & himagic) {

			const char *cp = (const char *) (longword_ptr - 1);
			char_ptr = cp;
			if (cp[0] == 0)
				break;
			char_ptr = cp + 1;
			if (cp[1] == 0)
				break;
			char_ptr = cp + 2;
			if (cp[2] == 0)
				break;
			char_ptr = cp + 3;
			if (cp[3] == 0)
				break;
			if (sizeof (longword) > 4) {
				char_ptr = cp + 4;
				if (cp[4] == 0)
					break;
				char_ptr = cp + 5;
				if (cp[5] == 0)
					break;
				char_ptr = cp + 6;
				if (cp[6] == 0)
					break;
				char_ptr = cp + 7;
				if (cp[7] == 0)
					break;
			}
		}
		char_ptr = end_ptr;
	}

	if (char_ptr > end_ptr)
		char_ptr = end_ptr;
	return char_ptr - str;
}

#ifndef STRNLEN
libc_hidden_def(__strnlen)
weak_alias(__strnlen, strnlen)
#endif
libc_hidden_def(strnlen)