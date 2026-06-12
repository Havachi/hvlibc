#ifndef _INTTYPES_H
#define  _INTTYPES_H 1

#include <stdint.h>
#include <sys/cdefs.h>
#include <features.h>
#ifndef ____gwchar_t_defined
# ifdef __cplusplus
#  define __gwchar_t wchar_t
# elif defined __WCHAR_TYPE__
typedef __WCHAR_TYPE__ __gwchar_t;
# else
#  define __need_wchat_t
#  include <stddef.h>
typedef wchar_t __gwchar_t;
# endif
# define ____gwchar_t_defined	1
#endif

# if __WORDSIZE == 64
#  define __PRI64_PREFIX	"l"
#  define __PRIPTR_PREFIX	"l"
# else
#  define __PRI64_PREFIX	"ll"
#  define __PRIPTR_PREFIX
# endif

# define PRId8		"hhd"
# define PRId16		"hd"
# define PRId32		"d"
# define PRId64		__PRI64_PREFIX "d"

# define PRIdLEAST8	"hhd"
# define PRIdLEAST16	"hd"
# define PRIdLEAST32	"d"
# define PRIdLEAST64	__PRI64_PREFIX "d"

# define PRIdFAST8	"hhd"
# define PRIdFAST16	__PRIPTR_PREFIX "d"
# define PRIdFAST32	__PRIPTR_PREFIX "d"
# define PRIdFAST64	__PRI64_PREFIX "d"


# define PRIi8		"hhi"
# define PRIi16		"hi"
# define PRIi32		"i"
# define PRIi64		__PRI64_PREFIX "i"

# define PRIiLEAST8	"hhi"
# define PRIiLEAST16	"hi"
# define PRIiLEAST32	"i"
# define PRIiLEAST64	__PRI64_PREFIX "i"

# define PRIiFAST8	"hhi"
# define PRIiFAST16	__PRIPTR_PREFIX "i"
# define PRIiFAST32	__PRIPTR_PREFIX "i"
# define PRIiFAST64	__PRI64_PREFIX "i"

/* Octal notation.  */
# define PRIo8		"hho"
# define PRIo16		"ho"
# define PRIo32		"o"
# define PRIo64		__PRI64_PREFIX "o"

# define PRIoLEAST8	"hho"
# define PRIoLEAST16	"ho"
# define PRIoLEAST32	"o"
# define PRIoLEAST64	__PRI64_PREFIX "o"

# define PRIoFAST8	"hho"
# define PRIoFAST16	__PRIPTR_PREFIX "o"
# define PRIoFAST32	__PRIPTR_PREFIX "o"
# define PRIoFAST64	__PRI64_PREFIX "o"

/* Unsigned integers.  */
# define PRIu8		"hhu"
# define PRIu16		"hu"
# define PRIu32		"u"
# define PRIu64		__PRI64_PREFIX "u"

# define PRIuLEAST8	"hhu"
# define PRIuLEAST16	"hu"
# define PRIuLEAST32	"u"
# define PRIuLEAST64	__PRI64_PREFIX "u"

# define PRIuFAST8	"hhu"
# define PRIuFAST16	__PRIPTR_PREFIX "u"
# define PRIuFAST32	__PRIPTR_PREFIX "u"
# define PRIuFAST64	__PRI64_PREFIX "u"

/* lowercase hexadecimal notation.  */
# define PRIx8		"hhx"
# define PRIx16		"hx"
# define PRIx32		"x"
# define PRIx64		__PRI64_PREFIX "x"

# define PRIxLEAST8	"hhx"
# define PRIxLEAST16	"hx"
# define PRIxLEAST32	"x"
# define PRIxLEAST64	__PRI64_PREFIX "x"

# define PRIxFAST8	"hhx"
# define PRIxFAST16	__PRIPTR_PREFIX "x"
# define PRIxFAST32	__PRIPTR_PREFIX "x"
# define PRIxFAST64	__PRI64_PREFIX "x"

/* UPPERCASE hexadecimal notation.  */
# define PRIX8		"hhX"
# define PRIX16		"hX"
# define PRIX32		"X"
# define PRIX64		__PRI64_PREFIX "X"

# define PRIXLEAST8	"hhX"
# define PRIXLEAST16	"hX"
# define PRIXLEAST32	"X"
# define PRIXLEAST64	__PRI64_PREFIX "X"

# define PRIXFAST8	"hhX"
# define PRIXFAST16	__PRIPTR_PREFIX "X"
# define PRIXFAST32	__PRIPTR_PREFIX "X"
# define PRIXFAST64	__PRI64_PREFIX "X"


/* Macros for printing `intmax_t' and `uintmax_t'.  */
# define PRIdMAX	__PRI64_PREFIX "d"
# define PRIiMAX	__PRI64_PREFIX "i"
# define PRIoMAX	__PRI64_PREFIX "o"
# define PRIuMAX	__PRI64_PREFIX "u"
# define PRIxMAX	__PRI64_PREFIX "x"
# define PRIXMAX	__PRI64_PREFIX "X"


/* Macros for printing `intptr_t' and `uintptr_t'.  */
# define PRIdPTR	__PRIPTR_PREFIX "d"
# define PRIiPTR	__PRIPTR_PREFIX "i"
# define PRIoPTR	__PRIPTR_PREFIX "o"
# define PRIuPTR	__PRIPTR_PREFIX "u"
# define PRIxPTR	__PRIPTR_PREFIX "x"
# define PRIXPTR	__PRIPTR_PREFIX "X"

# define SCNd8		"hhd"
# define SCNd16		"hd"
# define SCNd32		"d"
# define SCNd64		__PRI64_PREFIX "d"

# define SCNdLEAST8	"hhd"
# define SCNdLEAST16	"hd"
# define SCNdLEAST32	"d"
# define SCNdLEAST64	__PRI64_PREFIX "d"

# define SCNdFAST8	"hhd"
# define SCNdFAST16	__PRIPTR_PREFIX "d"
# define SCNdFAST32	__PRIPTR_PREFIX "d"
# define SCNdFAST64	__PRI64_PREFIX "d"

/* Signed decimal notation.  */
# define SCNi8		"hhi"
# define SCNi16		"hi"
# define SCNi32		"i"
# define SCNi64		__PRI64_PREFIX "i"

# define SCNiLEAST8	"hhi"
# define SCNiLEAST16	"hi"
# define SCNiLEAST32	"i"
# define SCNiLEAST64	__PRI64_PREFIX "i"

# define SCNiFAST8	"hhi"
# define SCNiFAST16	__PRIPTR_PREFIX "i"
# define SCNiFAST32	__PRIPTR_PREFIX "i"
# define SCNiFAST64	__PRI64_PREFIX "i"

/* Unsigned decimal notation.  */
# define SCNu8		"hhu"
# define SCNu16		"hu"
# define SCNu32		"u"
# define SCNu64		__PRI64_PREFIX "u"

# define SCNuLEAST8	"hhu"
# define SCNuLEAST16	"hu"
# define SCNuLEAST32	"u"
# define SCNuLEAST64	__PRI64_PREFIX "u"

# define SCNuFAST8	"hhu"
# define SCNuFAST16	__PRIPTR_PREFIX "u"
# define SCNuFAST32	__PRIPTR_PREFIX "u"
# define SCNuFAST64	__PRI64_PREFIX "u"

/* Octal notation.  */
# define SCNo8		"hho"
# define SCNo16		"ho"
# define SCNo32		"o"
# define SCNo64		__PRI64_PREFIX "o"

# define SCNoLEAST8	"hho"
# define SCNoLEAST16	"ho"
# define SCNoLEAST32	"o"
# define SCNoLEAST64	__PRI64_PREFIX "o"

# define SCNoFAST8	"hho"
# define SCNoFAST16	__PRIPTR_PREFIX "o"
# define SCNoFAST32	__PRIPTR_PREFIX "o"
# define SCNoFAST64	__PRI64_PREFIX "o"

/* Hexadecimal notation.  */
# define SCNx8		"hhx"
# define SCNx16		"hx"
# define SCNx32		"x"
# define SCNx64		__PRI64_PREFIX "x"

# define SCNxLEAST8	"hhx"
# define SCNxLEAST16	"hx"
# define SCNxLEAST32	"x"
# define SCNxLEAST64	__PRI64_PREFIX "x"

# define SCNxFAST8	"hhx"
# define SCNxFAST16	__PRIPTR_PREFIX "x"
# define SCNxFAST32	__PRIPTR_PREFIX "x"
# define SCNxFAST64	__PRI64_PREFIX "x"


/* Macros for scanning `intmax_t' and `uintmax_t'.  */
# define SCNdMAX	__PRI64_PREFIX "d"
# define SCNiMAX	__PRI64_PREFIX "i"
# define SCNoMAX	__PRI64_PREFIX "o"
# define SCNuMAX	__PRI64_PREFIX "u"
# define SCNxMAX	__PRI64_PREFIX "x"

/* Macros for scanning `intptr_t' and `uintptr_t'.  */
# define SCNdPTR	__PRIPTR_PREFIX "d"
# define SCNiPTR	__PRIPTR_PREFIX "i"
# define SCNoPTR	__PRIPTR_PREFIX "o"
# define SCNuPTR	__PRIPTR_PREFIX "u"
# define SCNxPTR	__PRIPTR_PREFIX "x"

__BEGIN_DECLS
#if __WORDSIZE == 64

typedef struct {
	long int quot;
	long int rem;
} imaxdiv_t;

#else

typedef struct {
	__extension__ long long int quot;
	__extension__ long long int rem;
} imaxdiv_t;
#endif

extern intmax_t imaxabs (intmax_t __n) __THROW __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __THROW __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
			   char **__restrict __endptr, int __base) __THROW;

extern uintmax_t strtoumax (const char *__restrict __nptr,
			    char ** __restrict __endptr, int __base) __THROW;

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
			   __gwchar_t **__restrict __endptr, int __base)
     __THROW;

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
			    __gwchar_t ** __restrict __endptr, int __base)
     __THROW;
#endif