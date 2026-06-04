#ifndef _HVLIBC_STRING_H
#define _HVLIBC_STRING_H 1

#include <stddef.h>

extern void    *memcpy(void * __dest, const void * __src, size_t __n);
extern void    *memmove(void *__dest, const void *__src, size_t __n);
extern void    *memccpy(void *__dest, const void *__src, int __c, size_t __n);
extern void    *memset(void *__s, int __c, size_t __n);
extern int      memcmp(const void *__s1, const void *__s2, size_t __n);
extern void    *memchr(const void *__s, int __c, size_t __n);
extern void		*__mempcpy(void *__dest, const void * __src, size_t __n);

extern char    *strcpy(char *__dest, const char *__src);
extern char    *strcat(char *__dest, const char *__src);
extern char    *strchr(const char *__s, int __c);
extern int      strcmp(const char *__s1, const char *__s2);
extern int      strcoll(const char *__s1, const char *__s2);
extern size_t   strcspn(const char *__s1, const char *__s2);
extern char    *strdup(const char *__s);
extern char    *strerror(int __e);
extern size_t   strlen(const char *__s);
extern char    *strncat(char *__dest, const char *__src, size_t __n);
extern int      strncmp(const char *__s1, const char *__s2, size_t __n);
extern char    *strncpy(char *__dest, const char *__src, size_t __n);
extern char    *strpbrk(const char *__s, const char *__accept);
extern char    *strrchr(const char *__s, int __c);
extern size_t   strspn(const char *__s, const char *__accept);
extern char    *strstr(const char *__haystack, const char *__needle);
extern char    *strtok(char *__s, const char *__delim);
extern char    *strtok_r(char *__s, const char *__delim, char **__save_ptr);
extern size_t   strxfrm(char *__dest, const char *__src, size_t __n);

#endif