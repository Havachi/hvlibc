#include <string.h>


char	*strtok(char *s, const char *delim)
{
	static char *olds;
	return __strtok_r(s, delim, &olds);
}
