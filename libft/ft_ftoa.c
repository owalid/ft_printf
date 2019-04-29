/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/12 15:26:58 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long			ft_cast_double_to_long(double nbr, int precision)
{
	long		cast_long;

	cast_long = (long)nbr;
	if ((cast_long % 10 <= 5 && cast_long % 10 != 0)
			|| precision == get_size_nb(cast_long))
		return (cast_long + 1);
	else
		return (cast_long);
}

char			*ft_ftoa(double f, int precision)
{
	double	second_part;
	int		power_part;
	char	*strfir_part;
	char	*strsec_part;
	char	*result;

	power_part = (int)f;
	second_part = f - (double)power_part;
	second_part = second_part * ft_pow(10, precision - 1);
	result = ft_strnew(get_size_nb(power_part) + get_size_nb(second_part) + 1);
	strfir_part = ft_strnew(get_size_nb(power_part) + 1);
	strfir_part = ft_itoa(power_part);
	strfir_part[get_size_nb(power_part)] = '.';
	strsec_part = ft_itoa(ft_cast_double_to_long(second_part, precision));
	result = ft_strjoin(strfir_part, strsec_part);
	return (result);
}