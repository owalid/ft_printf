#include "ft_printf.h"

char		*ft_printf_u(va_list ap, t_output *out)
{
	unsigned long long 	nbr;
	char				*result;

	if (out->size_flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (out->size_flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (out->size_flag->j)
		nbr = va_arg(ap, intmax_t);
	else	
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_U(va_list ap, t_output *out)
{
	unsigned long long 	nbr;
	char				*result;

	(void)out->size_flag;
	nbr = va_arg(ap, unsigned long);
	result = utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_X(va_list ap, t_output *out)
{
	unsigned long long	nbr;
	char				*result;

	if (out->size_flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (out->size_flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (out->size_flag->j)
		nbr = va_arg(ap, uintmax_t);
	else	
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 16);
	return (result);
}

char		*ft_printf_x(va_list ap, t_output *out)
{
	unsigned long long	nbr;
	char				*result;

	if (out->size_flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (out->size_flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (out->size_flag->j)
		nbr = va_arg(ap, uintmax_t);
	else
		nbr = va_arg(ap, unsigned int);
	result = utoa_base(nbr, 16);
	result = ft_strlowcase(result);
	return (result);
}

char		*ft_printf_f(va_list ap, t_output *out)
{
	char		*result;
	double		nbr;


	nbr = va_arg(ap, double);
	if (out->size_flag->no_prec == 1)
		result = ft_ftoa(nbr, 0);
	else if (out->size_flag->precision)
		result = ft_ftoa(nbr, out->size_flag->precision);
	else
		result = ft_ftoa(nbr, 6);
	out->size_flag->precision = 0;
	return (result);
}
