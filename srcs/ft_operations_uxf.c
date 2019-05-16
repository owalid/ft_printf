/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_uxf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:59:36 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 07:54:45 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_u(va_list ap, t_output *out)
{
	unsigned long long	nbr;
	char				*result;

	if (out->size_flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (out->size_flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else if (out->size_flag->j)
		nbr = va_arg(ap, intmax_t);
	else
		nbr = va_arg(ap, unsigned int);
	result = ft_utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_ubig(va_list ap, t_output *out)
{
	unsigned long long	nbr;
	char				*result;

	(void)out->size_flag;
	nbr = va_arg(ap, unsigned long);
	result = ft_utoa_base(nbr, 10);
	return (result);
}

char		*ft_printf_xbig(va_list ap, t_output *out)
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
	result = ft_utoa_base(nbr, 16);
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
	result = ft_utoa_base(nbr, 16);
	result = ft_strlowcase(result);
	return (result);
}

char		*ft_printf_f(va_list ap, t_output *out)
{
	char		*result;
	double		nbr;
	long long	tmp;

	nbr = va_arg(ap, double);
	if (out->size_flag->no_prec == 1)
	{
		tmp = (long long)nbr;
		result = ft_itoa(tmp);
		if (nbr < 0 && tmp == 0)
			result = ft_strjoin_char('-', result, 1);
		return (result);
	}
	else if (out->size_flag->precision)
		result = ft_ftoa(nbr, out->size_flag->precision);
	else
		result = ft_ftoa(nbr, 6);
	out->size_flag->precision = 0;
	return (result);
}
