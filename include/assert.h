#ifdef _ASSERT_H
#undef assert
#endif
#define _ASSERT_H 1

#if __STDC_VERSION__ >= 201112L
# define __STDC_VERSION_ASSERT_H__ 201112L
# ifdef NDEBUG
#  define assert(...) ((void)0)
# else /* NDEBUG */
#  define assert(...) /*TBD*/
# endif /* NDEBUG */
#else /* __STDC_VERSION__ */
# ifdef NDEBUG
#  define assert(cond) ((void)0)
# else /* NDEBUG */
#  define assert(cond) if(!cond) {abort()}
# endif /* NDEBUG */
#endif /* __STDC_VERSION__ */