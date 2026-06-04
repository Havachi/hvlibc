#ifndef _LIBC_SYMBOLS_H
#define _LIBC_SYMBOLS_H 1

#ifdef __ASSEMBLER__
# define attribute_hidden .hidden
#else
# define attribute_hidden __attribute__((visibility("hidden")))
#endif

#define strong_alias(name, aliasname) __strong_alias(name, aliasname)
#define __strong_alias(name, aliasname) \
	extern __typeof (name) aliasname __attribute__((alias (#name)))

#define weak_alias(name, aliasname) __weak_alias(name, aliasname)
#define __weak_alias(name, aliasname) \
	extern __typeof (name) aliasname __attribute__ ((weak, alias (#name)));



#define hidden_def(name) \
	strong_alias(name, __GI_##name) attribute_hidden;

#define libc_hidden_def(name) \
	hidden_def(name)

#define libc_hidden_builtin_def(name) \
	libc_hidden_def(name)

#endif