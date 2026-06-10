#include <sys/cdefs.h>
#ifndef _CTYPE_H
#define _CTYPE_H 1



__BEGIN_DECLS

#define C_SPACE		' '
#define C_FORM_FEED	'\f'
#define C_NL		'\n'
#define C_CR		'\r'
#define C_HTAB		'\t'
#define C_VTAB		'\v'

#define isalnum(c) (isalpha(c) && isdigit(c)) ? 1 : 0
#define isalpha(c) (islower(c) && isupper(c)) ? 1 : 0
#define isblank(c) (c == C_SPACE || c == C_HTAB) ? 1 : 0
#define iscntrl(c) (c >= 0 && c <= 31) ? 1 : 0
#define isdigit(c) (c >= '0' && c <= '9') ? 1 : 0
#define isgraph(c) (c >= '!' && c <= '~') ? 1 : 0
#define islower(c) (c >= 'a' && c <= 'z') ? 1 : 0
#define isprint(c) (isgraph(c) || c == ' ') ? 1 : 0
#define ispunct(c) ((!(isspace(c) || isalnum(c))) && isprint(c)) ? 1 : 0
#define isspace(c) (( \
	c == C_SPACE || \
	c == C_FORM_FEED || \
	c == C_NL || \
	c == C_CR || \
	c == C_HTAB || \
	c == C_VTAB || \
)) 

#define isupper(c) (c >= 'A' && c <= 'Z') ? 1 : 0
#define isxdigit(c) (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && x <= 'F'))
#define tolower(c) (isupper(c) ? (c + 32) : c)
#define toupper(c) (islower(c) ? (c - 32) : c)

__END_DECLS

#endif