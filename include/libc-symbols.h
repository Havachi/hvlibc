#ifndef _LIBC_SYMBOLS_H
#define _LIBC_SYMBOLS_H 1

#ifdef MODULE_NAME

#define PASTE_NAME1(a,b) a##b
#define PASTE_NAME(a,b) PASTE_NAME1(a,b)
#define IN_MODULE	PASTE_NAME (MODULE_, MODULE_NAME)
#define IS_IN(lib)	(IN_MODULE == MODULE_##lib)
#define IS_IN_LIB	(IN_MODULE > MODULE_LIBS_BEGIN)
#if IS_IN (testsuite) || defined IS_IN_build || defined __cplusplus
#define _ISOMAC 1
#endif
 
#else

# define IS_IN(lib) 0
# define IS_IN_LIB 0
# define IN_MODULE (-1)
#endif


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

#ifndef __ASSEMBLER__
# define __hidden_proto_hiddenattr(attrs...) \
	__attribute__ ((visibility ("hidden"), ##attrs))

# define hidden_proto(name, attrs...) \
	__hidden_proto (name, __thread, __GI_##name, ##attrs)

# define __hidden_proto(name, thread, internal, attrs...) \
	extern thread __typeof (name) name __asm__ (__hidden_asmname (#internal)) \
	__hidden_proto_hiddenattr(attrs);

# define __hidden_asmname(name) \
	__hidden_asmname1 (__USER_LABEL_PREFIX__, name)

# define __hidden_asmname1(prefix, name) __hidden_asmname2(prefix, name)
# define __hidden_asmname2(prefix, name) #prefix name
#else /* ASSEMBLER */
# define __hidden_def(name) strong_alias (name, __GI_##name)
# define __hidden_weak(name) __hidden_def (name)

#endif

#define libc_hidden_proto(name, attrs...) hidden_proto(name, ##attrs)

#endif