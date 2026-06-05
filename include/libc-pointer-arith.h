#ifndef _LIBC_POINTER_ARITH_H
#define _LIBC_POINTER_ARITH_H 1

#include <stdint.h>

#define _pointer_type(type) (__builtin_classify_type ((type) 0) == 5)

#define __integer_if_pointer_type_sub(T, P) \
	__typeof__ (*(0 ? (__typeof__ (0 ? (T *) 0 : (void *) (P))) 0 \
			: (__typeof__ (0 ? (intptr_t *) 0 : (void *) (!(P)))) 0))

# define __integer_if_pointer_type(expr) \
  __integer_if_pointer_type_sub(__typeof__ ((__typeof__ (expr)) 0), \
				__pointer_type (__typeof__ (expr)))

# define cast_to_integer(val) ((__integer_if_pointer_type (val)) (val))
#define ALIGN_DOWN(base, size)	((base) & -((__typeof__ (base)) (size)))
#define ALIGN_UP(base, size)	ALIGN_DOWN ((base) + (size) - 1, (size))
#define PTR_ALIGN_DOWN(base, size) \
		((__typeof__ (base)) ALIGN_DOWN ((uintptr_t) (base), (size)))
#define PTR_ALIGN_UP(base, size) \
		((__typeof__ (base)) ALIGN_UP ((uintptr_t) (base), (size)))
#endif