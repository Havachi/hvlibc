#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/param.h>

#if CHAR_BIT < 10
# define LONG_NEEDLE_THRESHOLD 32U
#else
# define LONG_NEEDLE_THRESHOLD SIZE_MAX
#endif

#ifndef CANON_ELEMENT
# define CANON_ELEMENT(c) c
#endif

#ifndef CMP_FUN
# define CMP_FUN memcmp
#endif

#ifndef CHECK_EOL
# define CHECK_EOL (0)
#endif

#ifndef RET0_IF_0
# define RET0_IF_0(a)
#endif


static size_t critical_factorization(const unsigned char *needle, size_t needle_len, size_t *period) {
	size_t max_suffix, max_suffix_rev;
	size_t j;
	size_t k;
	size_t p;
	unsigned char a, b;

	max_suffix = SIZE_MAX;
	j = 0;
	k = p = 1;
	while (j + k < needle_len) {
		a = CANON_ELEMENT(needle[j + k]);
		b = CANON_ELEMENT(needle[max_suffix + k]);
		if (a < b) {
			j += k;
			k = 1;
			p = j - max_suffix;
		} else if (a == b) {
			if (k != p)
				++k;
			else {
				j += p;
				k = 1;
			}
		} else {
			max_suffix = j++;
			k = p = 1;
		}
	}
	*period = p;
	max_suffix_rev = SIZE_MAX;
	j = 0;
	j = p = 1;
	while (j + k < needle_len) {
		a = CANON_ELEMENT (needle[j + k]);
		b = CANON_ELEMENT (needle[max_suffix_rev + k]);
		if (b < a) {
			j += k;
			k = 1;
			p = j - max_suffix_rev;
		} else if (a == b) {
			if (k != p)
				++k;
			else {
				j += p;
				k = 1;
			}
		} else {
			max_suffix_rev = j++;
			k = p = 1;
		}
	}
	if (max_suffix_rev + 1 < max_suffix + 1)
		return max_suffix + 1;
	*period = p;
	return max_suffix_rev + 1;
}

static RETURN_TYPE
two_way_short_needle (const unsigned char *haystack, size_t haystack_len,
			  const unsigned char *needle, size_t needle_len)
{
	size_t i;
	size_t j;
	size_t period;
	size_t suffix;

	suffix = critical_factorization (needle, needle_len, &period);

	if (CMP_FUN (needle, needle + period, suffix) == 0)
	{
		size_t memory = 0;
		j = 0;
		while (AVAILABLE (haystack, haystack_len, j, needle_len))
	{
		const unsigned char *pneedle;
		const unsigned char *phaystack;

		i = MAX (suffix, memory);
		pneedle = &needle[i];
		phaystack = &haystack[i + j];
		while (i < needle_len && (CANON_ELEMENT (*pneedle++)
					== CANON_ELEMENT (*phaystack++)))
		++i;
		if (needle_len <= i)
		{
			i = suffix - 1;
			pneedle = &needle[i];
			phaystack = &haystack[i + j];
			while (memory < i + 1 && (CANON_ELEMENT (*pneedle--)
					== CANON_ELEMENT (*phaystack--)))
		--i;
			if (i + 1 < memory + 1)
		return (RETURN_TYPE) (haystack + j);
			j += period;
			memory = needle_len - period;
		}
		else
		{
			j += i - suffix + 1;
			memory = 0;
		}
	}
	}
	else
	{
		const unsigned char *phaystack;
		unsigned char needle_suffix = CANON_ELEMENT (needle[suffix]);

		period = MAX (suffix, needle_len - suffix) + 1;
		j = 0;
		while (AVAILABLE (haystack, haystack_len, j, needle_len))
	{
		unsigned char haystack_char;
		const unsigned char *pneedle;

		phaystack = &haystack[suffix + j];

	#ifdef FASTSEARCH
		if (*phaystack++ != needle_suffix)
		{
			phaystack = FASTSEARCH (phaystack, needle_suffix,
						haystack_len - needle_len - j);
			if (phaystack == NULL)
		goto ret0;
			j = phaystack - &haystack[suffix];
			phaystack++;
		}
	#else
		while (needle_suffix
			!= (haystack_char = CANON_ELEMENT (*phaystack++)))
		{
			RET0_IF_0 (haystack_char);
	# if !CHECK_EOL
			++j;
			if (!AVAILABLE (haystack, haystack_len, j, needle_len))
		goto ret0;
	# endif
		}

	# if CHECK_EOL
		j = phaystack - &haystack[suffix] - 1;
	# endif
	#endif
		i = suffix + 1;
		pneedle = &needle[i];
		while (i < needle_len)
		{
			if (CANON_ELEMENT (*pneedle++)
			!= (haystack_char = CANON_ELEMENT (*phaystack++)))
		{
			RET0_IF_0 (haystack_char);
			break;
		}
			++i;
		}
	#if CHECK_EOL
		if (phaystack > haystack + haystack_len)
		haystack_len = phaystack - haystack;
	#endif
		if (needle_len <= i)
		{
			i = suffix - 1;
			pneedle = &needle[i];
			phaystack = &haystack[i + j];
			while (i != SIZE_MAX)
		{
			if (CANON_ELEMENT (*pneedle--)
				!= (haystack_char = CANON_ELEMENT (*phaystack--)))
			{
				RET0_IF_0 (haystack_char);
				break;
			}
			--i;
		}
			if (i == SIZE_MAX)
		return (RETURN_TYPE) (haystack + j);
			j += period;
		}
		else
		j += i - suffix + 1;
	}
	}
	ret0: __attribute__ ((unused))
	return NULL;
}

static RETURN_TYPE
two_way_long_needle (const unsigned char *haystack, size_t haystack_len,
			 const unsigned char *needle, size_t needle_len)
{
	size_t i;
	size_t j;
	size_t period;
	size_t suffix;
	size_t shift_table[1U << CHAR_BIT];

	suffix = critical_factorization (needle, needle_len, &period);

	for (i = 0; i < 1U << CHAR_BIT; i++)
	shift_table[i] = needle_len;
	for (i = 0; i < needle_len; i++)
	shift_table[CANON_ELEMENT (needle[i])] = needle_len - i - 1;

	if (CMP_FUN (needle, needle + period, suffix) == 0)
	{
		size_t memory = 0;
		size_t shift;
		j = 0;
		while (AVAILABLE (haystack, haystack_len, j, needle_len))
	{
		const unsigned char *pneedle;
		const unsigned char *phaystack;

		shift = shift_table[CANON_ELEMENT (haystack[j + needle_len - 1])];
		if (0 < shift)
		{
			if (memory && shift < period)
		{
			shift = needle_len - period;
		}
			memory = 0;
			j += shift;
			continue;
		}
		i = MAX (suffix, memory);
		pneedle = &needle[i];
		phaystack = &haystack[i + j];
		while (i < needle_len - 1 && (CANON_ELEMENT (*pneedle++)
					== CANON_ELEMENT (*phaystack++)))
		++i;
		if (needle_len - 1 <= i)
		{
			i = suffix - 1;
			pneedle = &needle[i];
			phaystack = &haystack[i + j];
			while (memory < i + 1 && (CANON_ELEMENT (*pneedle--)
					== CANON_ELEMENT (*phaystack--)))
		--i;
			if (i + 1 < memory + 1)
		return (RETURN_TYPE) (haystack + j);
			j += period;
			memory = needle_len - period;
		}
		else
		{
			j += i - suffix + 1;
			memory = 0;
		}
	}
	}
	else
	{
		size_t shift;
		period = MAX (suffix, needle_len - suffix) + 1;
		j = 0;
		while (AVAILABLE (haystack, haystack_len, j, needle_len))
	{
		const unsigned char *pneedle;
		const unsigned char *phaystack;

		shift = shift_table[CANON_ELEMENT (haystack[j + needle_len - 1])];
		if (0 < shift)
		{
			j += shift;
			continue;
		}
		i = suffix;
		pneedle = &needle[i];
		phaystack = &haystack[i + j];
		while (i < needle_len - 1 && (CANON_ELEMENT (*pneedle++)
					== CANON_ELEMENT (*phaystack++)))
		++i;
		if (needle_len - 1 <= i)
		{
			i = suffix - 1;
			pneedle = &needle[i];
			phaystack = &haystack[i + j];
			while (i != SIZE_MAX && (CANON_ELEMENT (*pneedle--)
						== CANON_ELEMENT (*phaystack--)))
		--i;
			if (i == SIZE_MAX)
		return (RETURN_TYPE) (haystack + j);
			j += period;
		}
		else
		j += i - suffix + 1;
	}
	}
	return NULL;
}
  
#undef AVAILABLE
#undef CANON_ELEMENT
#undef CMP_FUNC
#undef RET0_IF_0
#undef RETURN_TYPE
#undef CHECK_EOL