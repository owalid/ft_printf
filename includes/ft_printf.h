#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/////////////////////
# include <stdio.h>
////////////////////

# include <stdarg.h>
# include <wchar.h>
# include "libft.h"


typedef struct 		s_sizeflag
{
	short		h;
	short		hh;
	short		l;
	short		ll;
	short		bigl;
	short		j;
	short		z;
	short		no_prec;
	size_t		precision;
}					t_sizeflag;

typedef struct 		s_option
{
	short		hash;
	short		space;
	short		zero;
	short		min;
	short		plus;
	short		point;
}					t_option;


typedef struct		s_output
{
	char		*taille;
	char		*str;
	t_option	*option;
	t_sizeflag 	*size_flag;
	char 		conv_type;
	int			is_null;
	size_t		minsize;
}					t_output;

typedef struct 		s_prtfop
{
	char 	id;
	char	*(*ft_transform)(va_list argv, t_sizeflag *flag);
}					t_prtfop;
/*
**	ft_printf.c
*/
int			ft_printf(const char *format, ...);
int		ft_formater(t_output *output, int opt);
/*
**	ft_print.c
*/
void		add_char(char c, int opt);

/*
**	ft_operations.c
*/
char		*ft_printf_i_d(va_list nbr, t_sizeflag *flag);
char		*ft_printf_s(va_list str, t_sizeflag *flag);
char		*ft_printf_c(va_list nbr, t_sizeflag *flag);
char		*ft_printf_p(va_list ptr, t_sizeflag *flag);
char		*ft_printf_o(va_list nbr, t_sizeflag *flag);
char		*ft_printf_u(va_list nbr, t_sizeflag *flag);
char		*ft_printf_U(va_list ap, t_sizeflag *flag);
char		*ft_printf_X(va_list nbr, t_sizeflag *flag);
char		*ft_printf_x(va_list nbr, t_sizeflag *flag);
char		*ft_printf_f(va_list nbr, t_sizeflag *flag);

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
int		ft_is_opt(char c);

/*
**	clean.c
*/
void        ft_init_option(t_option *option);
void        ft_clean_output(t_output *out);
void        ft_init_output(t_output *out);
void        ft_init_sizeflag(t_sizeflag *flag);

/*
**	ft_utils.c
*/
char        *ft_add_blank(t_output *output, char *result, int opt);
void        send_char(char *result, int opt, size_t *i);
int        	is_no_prec(const char *format, int i);

/*
**	formater_df.c
*/
char	*ft_formater_with_option_df(t_output *output, size_t size);
int		ft_formater_df(t_output *output, int opt);

/*
**	ft_utils_df.c
*/
char        *option_plus_df(t_output *output, size_t size, char *result, size_t *i);
char        *option_point_df(t_output *output, char *result, size_t *i);
char        *option_zero_df(t_output *output, size_t size, char *result, size_t *i);
char        *option_space_df(t_output *output, char *result);

/*
**	formater_sc.c
*/
char	*ft_formater_with_option_sc(t_output *output, size_t size);
int		ft_formater_sc(t_output *output, int opt);


/*
**	formater_xX.c
*/
char	*ft_formater_with_option_xX(t_output *output, size_t size);
int		ft_formater_xX(t_output *output, int opt);

/*
**	formater_p.c
*/
char	*ft_formater_with_option_p(t_output *output, size_t size);
int		ft_formater_p(t_output *output, int opt);

/*
**	formater_p.c
*/
char	*ft_formater_with_option_u(t_output *output, size_t size);
int		ft_formater_u(t_output *output, int opt);

/*
**	formater_o.c
*/
char	*ft_formater_with_option_o(t_output *output, size_t size);
int		ft_formater_o(t_output *output, int opt);

/*
**	ft_utils_o.c
*/
char        *option_hash_o(t_output *output, size_t size, char *result, size_t *i);

/*
**	ft_utils_p.c
*/
char        *option_point_p(t_output *output, char *result, size_t size);

#endif
