#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/////////////////////
#include <stdio.h>
////////////////////

#include <stdarg.h>
#include "libft.h"

typedef struct 		s_prtfop
{
	char 	id;
	void	(*ft_transform)(va_list argv);
}					t_prtfop;

typedef struct		s_output
{
	char	*taille;
	char	*str;
	char	option;
	int		minsize;
	int		precision;
}					t_output;

/*
**	ft_printf.c
*/
int			ft_printf(const char *format, ...);

/*
**	ft_print.c
*/
void		add_char(char c, int opt);

/*
**	ft_operations.c
*/
void		ft_printf_i_d(va_list nbr);
void		ft_printf_s(va_list str);
void		ft_printf_c(va_list nbr);
void		ft_printf_p(va_list ptr);
void		ft_printf_o(va_list nbr);
void		ft_printf_u(va_list nbr);
void		ft_printf_xX(va_list nbr);

/*
**	ft_get_type.c
*/
int			is_char(char c);
int			is_str(char c);
int			is_integer(char c);
int			is_float(char c);


#endif
