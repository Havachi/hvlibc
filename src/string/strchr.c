#include <string.h>
#include <stdlib.h>

#undef strchr

#ifndef STRCHR
# define STRCHR strchr
#endif

char	*STRCHR(const char *s, int c_in)
{
	const unsigned char *char_ptr;
	const unsigned long int *longword_ptr;
	unsigned long int longword, magic_bits, charmask;
	unsigned char c;

	c = (unsigned char) c_in;

	for (char_ptr = (const unsigned char *) s;
		((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0;
		++char_ptr)
	{
		if (*char_ptr == c)
			return (void *) char_ptr;
		else if (*char_ptr == '\0')
			return NULL;
	}

	longword_ptr = (unsigned long int *) char_ptr;
	magic_bits = -1;
	magic_bits = magic_bits / 0xff * 0xfe << 1 >> 1 | 1;

	charmask = c | (c << 8);
	charmask |= charmask << 16;
	if (sizeof (longword) > 4)
		charmask |= (charmask << 16) << 16;
	if (sizeof (longword) > 8)
		abort ();
	for (;;)
    {
		longword = *longword_ptr++;

		if ((((longword + magic_bits)
			^ ~longword)
			& ~magic_bits) != 0 ||
			((((longword ^ charmask) + magic_bits) ^ ~(longword ^ charmask))
			& ~magic_bits) != 0)
		{
			const unsigned char *cp = (const unsigned char *) (longword_ptr - 1);

			if (*cp == c)
			return (char *) cp;
			else if (*cp == '\0')
			return NULL;
			if (*++cp == c)
			return (char *) cp;
			else if (*cp == '\0')
			return NULL;
			if (*++cp == c)
			return (char *) cp;
			else if (*cp == '\0')
			return NULL;
			if (*++cp == c)
			return (char *) cp;
			else if (*cp == '\0')
			return NULL;
			if (sizeof (longword) > 4)
			{
					if (*++cp == c)
				return (char *) cp;
					else if (*cp == '\0')
				return NULL;
					if (*++cp == c)
				return (char *) cp;
					else if (*cp == '\0')
				return NULL;
					if (*++cp == c)
				return (char *) cp;
					else if (*cp == '\0')
				return NULL;
					if (*++cp == c)
				return (char *) cp;
					else if (*cp == '\0')
				return NULL;
			}
		}
    }

  return NULL;
}

#ifdef weak_alias
# undef index
weak_alias(strchr, index)
#endif

libc_hidden_builtin_def(strchr)
