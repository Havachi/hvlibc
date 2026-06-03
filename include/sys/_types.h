#ifndef _MACHINE_TYPES_H
#define _MACHINE_TYPES_H 1

typedef signed char				__int8_t;
typedef unsigned char			__uint8_t;

typedef short					__int16_t;
typedef unsigned short			__uint16_t;

typedef int						__int32_t;
typedef unsigned int			__uint32_t;

typedef long long				__int64_t;
typedef unsigned long long		__uint64_t;

typedef	__int8_t		__int_least8_t;
typedef	__uint8_t		__uint_least8_t;
typedef	__int16_t		__int_least16_t;
typedef	__uint16_t		__uint_least16_t;
typedef	__int32_t		__int_least32_t;
typedef	__uint32_t		__uint_least32_t;
typedef	__int64_t		__int_least64_t;
typedef	__uint64_t		__uint_least64_t;

typedef	__int32_t		__int_fast8_t;
typedef	__uint32_t		__uint_fast8_t;
typedef	__int32_t		__int_fast16_t;
typedef	__uint32_t		__uint_fast16_t;
typedef	__int32_t		__int_fast32_t;
typedef	__uint32_t		__uint_fast32_t;
typedef	__int64_t		__int_fast64_t;
typedef	__uint64_t		__uint_fast64_t;
#define	__INT_FAST8_MIN		INT32_MIN
#define	__INT_FAST16_MIN	INT32_MIN
#define	__INT_FAST32_MIN	INT32_MIN
#define	__INT_FAST64_MIN	INT64_MIN
#define	__INT_FAST8_MAX		INT32_MAX
#define	__INT_FAST16_MAX	INT32_MAX
#define	__INT_FAST32_MAX	INT32_MAX
#define	__INT_FAST64_MAX	INT64_MAX
#define	__UINT_FAST8_MAX	UINT32_MAX
#define	__UINT_FAST16_MAX	UINT32_MAX
#define	__UINT_FAST32_MAX	UINT32_MAX
#define	__UINT_FAST64_MAX	UINT64_MAX

typedef	long				__intptr_t;
typedef	unsigned long		__uintptr_t;

typedef	__int64_t			__intmax_t;
typedef	__uint64_t			__uintmax_t;

typedef long				__register_t;

typedef unsigned long		__vaddr_t;
typedef unsigned long		__paddr_t;
typedef unsigned long		__vsize_t;
typedef unsigned long		__psize_t;

typedef	double				__double_t;
typedef	float				__float_t;
typedef long				__ptrdiff_t;
typedef	unsigned long		__size_t;
typedef	long				__ssize_t;
#if defined(__GNUC__) && __GNUC__ >= 3
typedef	__builtin_va_list	__va_list;
#else
typedef char *			__va_list;
#endif

#ifndef __cplusplus
typedef	int				__wchar_t;
#endif
typedef int				__wint_t;
typedef	int				__rune_t;
typedef	void *			__wctrans_t;
typedef	void *			__wctype_t;

#endif