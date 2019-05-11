#include "ft_printf.h"

char		*ft_printf_i_d(va_list ap, t_sizeflag *flag)
{
	char						*result;

	if (flag->ll)
		result =  ft_itoa_base(va_arg(ap, long long), 10);
	else if (flag->l)
		result =  ft_itoa_base(va_arg(ap, long), 10);
	else if (flag->z)
		result =  ft_itoa_base(va_arg(ap, ssize_t), 10);
	else if (flag->j)
		result =  ft_itoa_base(va_arg(ap, intmax_t), 10);
	else if (flag->hh)
		result =  ft_itoa_base((char)va_arg(ap, int), 10);
	else if (flag->h)
		result =  ft_itoa_base((short)va_arg(ap, int), 10);
	else
		result =  ft_itoa_base(va_arg(ap, int), 10);
	// result = ft_itoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_s(va_list ap, t_sizeflag *flag)
{
	char	*result;
	(void)flag;
	result = va_arg(ap, char*);
	return (result);
}

char		*ft_printf_c(va_list ap, t_sizeflag *flag)
{
	char	*result;
	
	(void)flag;
	result = ft_str_from_char(va_arg(ap, int));
	return (result);
}

char		*ft_printf_p(va_list ap, t_sizeflag *flag)
{
	char			*result;
	char			*add;
	int				i;
	unsigned long				ptr;

	(void)flag;
	i = -1;
	ptr = va_arg(ap, unsigned long long);
	add = ft_itoa_base(ptr, 16);
	result = ft_strlowcase(add);
	return(result);
}

char		*ft_printf_o(va_list ap, t_sizeflag *flag)
{	
	unsigned long long	nbr;
	char				*result;

	if (flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else	
		nbr = va_arg(ap, unsigned int);
	result = ft_itoa_base(nbr, 8);
	return(result);
}

char		*ft_printf_u(va_list ap, t_sizeflag *flag)
{
	unsigned long long 	nbr;
	char			*result;

	if (flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (flag->j)
		nbr = va_arg(ap, intmax_t);
	else	
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_U(va_list ap, t_sizeflag *flag)
{
	unsigned long long 	nbr;
	char			*result;

	(void)flag;
	nbr = va_arg(ap, unsigned long);
	result = utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_X(va_list ap, t_sizeflag *flag)
{
	unsigned long long	nbr;
	char				*result;

	if (flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (flag->j)
		nbr = va_arg(ap, uintmax_t);
	else	
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 16);
	return (result);
}

char		*ft_printf_x(va_list ap, t_sizeflag *flag)
{
	unsigned long long	nbr;
	char				*result;

	if (flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (flag->j)
		nbr = va_arg(ap, uintmax_t);
	else	
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 16);
	result = ft_strlowcase(result);
	return (result);
}

char		*ft_printf_f(va_list ap, t_sizeflag *flag)
{
	char		*result;
	double		nbr;

	nbr = va_arg(ap, double);
	if (flag->no_prec == 1)
		result = ft_ftoa(nbr, 0);	
	else if (flag->precision)
		result = ft_ftoa(nbr, flag->precision);
	else
		result = ft_ftoa(nbr, 6);
	flag->precision = 0;
	return (result);
}
