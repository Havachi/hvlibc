#ifndef _STDINT_H
#define _STDINT_H

#include <sys/types.h>

/* 7.20.1.1 [Exact-width integer types] */
#define __int8_t	__INT8_TYPE__
#define __int16_t	__INT16_TYPE__
#define __int32_t	__INT32_TYPE__
#define __int64_t	__INT64_TYPE__
#define __uint8_t	__UINT8_TYPE__
#define __uint16_t	__UINT16_TYPE__
#define __uint32_t	__UINT32_TYPE__
#define __uint64_t	__UINT64_TYPE__

typedef __int8_t		int8_t;
typedef __int16_t		int16_t;
typedef __int32_t		int32_t;
typedef __int64_t		int64_t;
typedef __uint8_t		uint8_t;
typedef __uint16_t		uint16_t;
typedef __uint32_t		uint32_t;
typedef __uint64_t		uint64_t;

/* 7.20.1.2 [Minimum-width integer types] */
#define _int_least8_t	__INT_LEAST8_TYPE__
#define _int_least16_t	__INT_LEAST16_TYPE__
#define _int_least32_t	__INT_LEAST32_TYPE__
#define _int_least64_t	__INT_LEAST64_TYPE__
#define _uint_least8_t	__UINT_LEAST8_TYPE__
#define _uint_least16_t	__UINT_LEAST16_TYPE__
#define _uint_least32_t	__UINT_LEAST32_TYPE__
#define _uint_least64_t	__UINT_LEAST64_TYPE__

typedef _int_least8_t	int_least8_t;
typedef _int_least16_t	int_least16_t;
typedef _int_least32_t	int_least32_t;
typedef _int_least64_t	int_least64_t;
typedef _uint_least8_t	uint_least8_t;
typedef _uint_least16_t	uint_least16_t;
typedef _uint_least32_t	uint_least32_t;
typedef _uint_least64_t	uint_least64_t;

/* 7.20.1.3 [Fastest minimum-width integer types] */
#define _int_fast8_t	__INT_FAST8_TYPE__
#define _int_fast16_t	__INT_FAST16_TYPE__
#define _int_fast32_t	__INT_FAST32_TYPE__
#define _int_fast64_t	__INT_FAST64_TYPE__
#define _uint_fast8_t	__UINT_FAST8_TYPE__
#define _uint_fast16_t	__UINT_FAST16_TYPE__
#define _uint_fast32_t	__UINT_FAST32_TYPE__
#define _uint_fast64_t	__UINT_FAST64_TYPE__
typedef _int_fast8_t	int_fast8_t;
typedef _int_fast16_t	int_fast16_t;
typedef _int_fast32_t	int_fast32_t;
typedef _int_fast64_t	int_fast64_t;
typedef _uint_fast8_t	uint_fast8_t;
typedef _uint_fast16_t	uint_fast16_t;
typedef _uint_fast32_t	uint_fast32_t;
typedef _uint_fast64_t	uint_fast64_t;

#define __intptr_t	__INTPTR_TYPE__
#define __uintptr_t	__UINTPTR_TYPE__
typedef __intptr_t	intptr_t;
typedef __uintptr_t	uintptr_t;

#define __intmax_t	__INTMAX_TYPE__
#define __uintmax_t	__UINTMAX_TYPE__
typedef __intmax_t	intmax_t;
typedef __uintmax_t	uintmax_t;

#define INT8_MAX	128
#define INT8_MIN	(-128)
#define UINT8_MAX	255

#define INT16_MAX	32767
#define INT16_MIN	(-32768)
#define UINT16_MAX	65535

#define INT32_MIN	(-2147483647 - 1)
#define INT32_MAX	2147483647
#define UINT32_MAX	4294967295U

#define INT64_MIN	(-9223372036854775807LL - 1LL)
#define INT64_MAX	9223372036854775807LL
#define UINT64_MAX	18446744073709551615ULL


#define INT_LEAST8_MIN     INT8_MIN
#define INT_LEAST8_MAX     INT8_MAX
#define UINT_LEAST8_MAX    UINT8_MAX

#define INT_LEAST16_MIN    INT16_MIN
#define INT_LEAST16_MAX    INT16_MAX
#define UINT_LEAST16_MAX   UINT16_MAX

#define INT_LEAST32_MIN    INT32_MIN
#define INT_LEAST32_MAX    INT32_MAX
#define UINT_LEAST32_MAX   UINT32_MAX

#define INT_LEAST64_MIN    INT64_MIN
#define INT_LEAST64_MAX    INT64_MAX
#define UINT_LEAST64_MAX   UINT64_MAX


#define INT_FAST8_MIN     INT8_MIN
#define INT_FAST8_MAX     INT8_MAX
#define UINT_FAST8_MAX    UINT8_MAX

#define INT_FAST16_MIN    INT16_MIN
#define INT_FAST16_MAX    INT16_MAX
#define UINT_FAST16_MAX   UINT16_MAX

#define INT_FAST32_MIN    INT32_MIN
#define INT_FAST32_MAX    INT32_MAX
#define UINT_FAST32_MAX   UINT32_MAX

#define INT_FAST64_MIN    INT64_MIN
#define INT_FAST64_MAX    INT64_MAX
#define UINT_FAST64_MAX   UINT64_MAX

#define INTPTR_MIN         INT64_MIN
#define INTPTR_MAX         INT64_MAX
#define UINTPTR_MAX        UINT64_MAX

#define INTMAX_MIN         INT64_MIN
#define INTMAX_MAX         INT64_MAX
#define UINTMAX_MAX        UINT64_MAX

#define PTRDIFF_MIN			(-65535)			
#define PTRDIFF_MAX			65535
#define SIZE_MAX			65535
#define SIG_ATOMIC_MIN
#define SIG_ATOMIC_MAX
#define WINT_MIN
#define WINT_MAX
#define WCHAR_MIN
#define WCHAR_MAX

#define INT8_C(value)		((int8_t)value)
#define INT16_C(value)		((int16_t)value)
#define INT32_C(value)		((int32_t)value)
#define INT64_C(value)		((int64_t)value)
#define INTMAX_C(value)		((intmax_t)value)

#define UINT8_C(value)		((uint8_t)value)
#define UINT16_C(value)		((uint16_t)value)
#define UINT32_C(value)		((uint32_t)value)
#define UINT64_C(value)		((uint64_t)value)
#define UINTMAX_C(value)	((uintmax_t)value)

#endif