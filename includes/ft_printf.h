/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:53:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/20 11:39:24 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"

# define ERR_MALLOC "Printf: error malloc"
# define ERR "Printf: error"

typedef struct	s_sizeflag
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
}				t_sizeflag;

typedef struct	s_option
{
	short		hash;
	short		space;
	short		zero;
	short		min;
	short		plus;
	short		point;
}				t_option;

typedef struct	s_output
{
	char		*str;
	t_option	option[1];
	t_sizeflag	size_flag[1];
	char		conv_type;
	int			is_null;
	size_t		minsize;
}				t_output;

typedef struct	s_prtfop
{
	char		id;
	char		*(*ft_transform)(va_list argv, t_output *output);
}				t_prtfop;
/*
**	ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				ft_formater(t_output *output, int opt);
char			*ft_converter(va_list ap, int *i, const char *format,
								t_output *out);
/*
**	ft_print.c
*/
void			add_char(char c, int opt, t_output *out);

/*
**	ft_operations_idscpo.c
*/
char			*ft_printf_i_d(va_list nbr, t_output *output);
char			*ft_printf_s(va_list str, t_output *output);
char			*ft_printf_c(va_list nbr, t_output *output);
char			*ft_printf_p(va_list ptr, t_output *output);
char			*ft_printf_o(va_list nbr, t_output *output);

/*
**	ft_operations_uxf.c
*/
char			*ft_printf_u(va_list nbr, t_output *output);
char			*ft_printf_ubig(va_list ap, t_output *output);
char			*ft_printf_xbig(va_list nbr, t_output *output);
char			*ft_printf_x(va_list nbr, t_output *output);
char			*ft_printf_f(va_list nbr, t_output *output);

/*
**	ft_get_type.c
*/
int				is_char(char c);
int				is_str(char c);
int				is_integer(char c);
int				is_float(char c);

/*
**	ft_option.c
*/
void			ft_is_option(char c, t_output *output);
int				ft_is_conv(char c);
int				ft_is_opt(char c);

/*
**	ft_init.c
*/
void			ft_init_option(t_option *option);
void			ft_clean_output(t_output *out);
void			ft_init_output(t_output *out);
void			ft_init_sizeflag(t_sizeflag *flag);

/*
**	ft_utils.c
*/
char			*ft_add_blank(t_output *output, char *result, int opt);
int				send_char(t_output *out, int opt, size_t *i);
int				is_no_prec(const char *format, int i);
void			ft_is_null(t_output *output);
int				one_option(t_output *out);

/*
**	ft_formater_df.c
*/
char			*ft_formater_with_option_df(t_output *output, size_t size);
int				ft_formater_df(t_output *out, int opt);

/*
**	ft_utils_df.c
*/
char			*option_plus_df(t_output *output, size_t size, char *res,
								size_t *i);
char			*option_point_df(t_output *output, char *res, size_t *i);
char			*option_zero_df(t_output *output, char *res, size_t *i);
char			*option_space_df(t_output *output, char *res);

/*
**	ft_formater_c.c
*/
int				ft_formater_c(t_output *out, int opt);

/*
**	ft_formater_sc.c
*/
char			*ft_formater_with_option_sc(t_output *out, size_t size);
int				ft_formater_sc(t_output *out, int opt);

/*
**	ft_formater_xx.c
*/
char			*ft_formater_with_option_xx(t_output *out, size_t size);
int				ft_formater_xx(t_output *out, int opt);

/*
**	ft_formater_p.c
*/
char			*ft_formater_with_option_p(t_output *output, size_t size);
int				ft_formater_p(t_output *output, int opt);

/*
**	ft_formater_p.c
*/
char			*ft_formater_with_option_u(t_output *out, size_t size);
int				ft_formater_u(t_output *out, int opt);

/*
**	ft_formater_o.c
*/
char			*ft_formater_with_option_o(t_output *out, size_t size);
int				ft_formater_o(t_output *out, int opt);

/*
**	ft_utils_o.c
*/
char			*option_hash_o(t_output *output, size_t size, char *res,
								size_t *i);

/*
**	ft_utils_p.c
*/
char			*option_point_p(t_output *output, char *result, size_t size);

/*
**	ft_parser.c
*/
void			pf_digit_prec(t_output *output, const char *format, int *i);
void			pf_digit(t_output *output, const char *format, int *i);
void			pf_prec(t_output *output, const char *format, int *i);
void			pf_conv(t_output *output, const char *format, int *i);
void			end_parser(t_output *output, va_list ap, const char *format,
							int i);

/*
**	ft_prepare.c
*/
void			ft_prepare_for_y(t_output *output, const char *format, int i);
void			ft_prepare(t_output *output, const char *format, int i,
							va_list ap);
void			ft_prepare_cond(t_output *output, const char *format, int i,
							va_list ap);

/*
**	ft_error.c
*/
void			ft_err(int id);

#endif
