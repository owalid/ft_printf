#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/////////////////////
#include <stdio.h>
////////////////////

#include <stdarg.h>
#include "libft.h"


typedef struct 		s_sizeflag
{
	short		h;
	short		hh;
	short		l;
	short		ll;
}					t_sizeflag;

typedef struct 		s_option
{
	short		hash;
	short		space;
	short		zero;
	short		min;
	short		plus;
}					t_option;


typedef struct		s_output
{
	char		*taille;
	char		*str;
	t_option	*option;
	t_sizeflag 	*size_flag;
	char 		conv_type;
	size_t		minsize;
	int			precision;
}					t_output;

typedef struct 		s_prtfop
{
	char 	id;
	char	*(*ft_transform)(va_list argv);
}					t_prtfop;
/*
**	ft_printf.c
*/
int			ft_printf(const char *format, ...);
void		ft_formater(t_output *output, int opt);
/*
**	ft_print.c
*/
void		add_char(char c, int opt);

/*
**	ft_operations.c
*/
char		*ft_printf_i_d(va_list nbr);
char		*ft_printf_s(va_list str);
char		*ft_printf_c(va_list nbr);
char		*ft_printf_p(va_list ptr);
char		*ft_printf_o(va_list nbr);
char		*ft_printf_u(va_list nbr);
char		*ft_printf_xX(va_list nbr);

/*
**	ft_get_type.c
*/
int			is_char(char c);
int			is_str(char c);
int			is_integer(char c);
int			is_float(char c);

/*
**	options.c
*/
void		ft_is_option(char c, t_output *output);
int			ft_is_conv(char c);

/*
**	clean.c
*/
void        ft_init_option(t_option *option);
void        ft_clean_output(t_output *out);
void        ft_init_output(t_output *out);
void        ft_init_sizeflag(t_sizeflag *flag);


#endif
