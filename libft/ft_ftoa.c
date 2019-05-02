/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/03 00:01:03 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//////////////////////
#include <stdio.h>
//////////////////////

long long		ft_cast_double_to_long(double nbr, int precision)
{
	long long	cast_long;

	cast_long = (long long)nbr;
	if (((nbr - (long long)cast_long) * 10) > 5)
		return (cast_long + 1);
	else
		return (cast_long);
}

char			*ft_ftoa(double f, size_t precision)
{
	long double	second_part;
	long long	power_part;
	char		*strfir_part;
	char		*strsec_part;
	char		*result;
	int			is_neg;

	is_neg = (f < 0) ? 1 : 0;
	power_part = (long long)f;
	if (precision <= 0)
	{
		strfir_part = ft_itoa(power_part);
		return (strfir_part);
	}
	second_part = (is_neg) ? f * -1 - (double)power_part * -1
							: f - (double)power_part;
	second_part = second_part * ft_pow(10, precision - 1);
	result = ft_strnew(get_size_nb(power_part) + get_size_nb(second_part)
												+ is_neg);
	strfir_part = ft_itoa(power_part);
	strfir_part[get_size_nb(power_part)] = '.';
	if (ft_cast_double_to_long(second_part, precision) == 0)
	{
		strsec_part = ft_strdup("000000");
		strsec_part = ft_strsub(strsec_part,  6 - precision, 6);
	}
	else
		strsec_part = ft_itoa(ft_cast_double_to_long(second_part, precision));
	result = ft_strjoin(strfir_part, strsec_part);
	return (result);
}
