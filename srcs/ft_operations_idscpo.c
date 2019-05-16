/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_idscpo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:58:46 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:16:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_i_d(va_list ap, t_output *out)
{
	char					*result;

	if (out->size_flag->ll)
		result = ft_itoa_base(va_arg(ap, long long), 10);
	else if (out->size_flag->l)
		result = ft_itoa_base(va_arg(ap, long), 10);
	else if (out->size_flag->z)
		result = ft_itoa_base(va_arg(ap, ssize_t), 10);
	else if (out->size_flag->j)
		result = ft_itoa_base(va_arg(ap, intmax_t), 10);
	else if (out->size_flag->hh)
		result = ft_itoa_base((char)va_arg(ap, int), 10);
	else if (out->size_flag->h)
		result = ft_itoa_base((short)va_arg(ap, int), 10);
	else
		result = ft_itoa_base(va_arg(ap, int), 10);
	return (result);
}

char		*ft_printf_s(va_list ap, t_output *out)
{
	char	*result;

	(void)out->size_flag;
	result = va_arg(ap, char*);
	if (!result)
	{
		out->is_null = 1;
		result = ft_strdup("(null)");
	}
	else if (!result[0])
		result = ft_strdup("");
	else
		result = ft_strdup(result);
	return (result);
}

char		*ft_printf_c(va_list ap, t_output *out)
{
	char	*result;

	(void)out->size_flag;
	result = ft_str_from_char(va_arg(ap, int));
	return (result);
}

char		*ft_printf_p(va_list ap, t_output *out)
{
	char				*result;
	char				*add;
	int					i;
	unsigned long		ptr;

	(void)out->size_flag;
	i = -1;
	ptr = va_arg(ap, unsigned long long);
	add = ft_itoa_base(ptr, 16);
	result = (add) ? ft_strlowcase(add) : add;
	return (result);
}

char		*ft_printf_o(va_list ap, t_output *out)
{
	unsigned long long	nbr;
	char				*result;

	if (out->size_flag->l)
		nbr = va_arg(ap, unsigned long);
	else if (out->size_flag->ll)
		nbr = va_arg(ap, unsigned long long);
	else
		nbr = va_arg(ap, unsigned int);
	result = ft_itoa_base(nbr, 8);
	return (result);
}
