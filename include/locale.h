#ifndef _LOCALE_H
#define _LOCALE_H 1

struct lconv {
	//Non-monetary numeric formatting parameters
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	//Monetary numeric formatting parameters
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	//Local monetary numeric formatting parameters
	char *currency_symbol;
	char frac_digits;
	char p_cs_precedes;
	char n_cs_precedes;
	char p_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
	//International monetary numeric formatting parameters
	char *int_curr_symbol;
	char int_fracs_digits;
	char int_p_cs_precedes;
	char int_n_cs_precedes;
	char int_p_sep_by_space;
	char int_n_sep_by_space;
	char int_p_sign_posn;
	char int_n_sign_posn;
};

#ifndef NULL
# define NULL ((void)(0))
#endif

#define LC_ALL		15	//1111
#define LC_COLLATE	1	//0001
#define LC_CTYPE	2	//0010
#define LC_MONETARY	4	//0100
#define LC_TIME		8	//1000

char *setlocale(int category, const char *locale);
struct lconv* localeconv();

#endif