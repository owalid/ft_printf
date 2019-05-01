/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/01 18:35:56 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//////////////////////
#include <stdio.h>
//////////////////////

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

char			*ft_ftoa(double f, size_t precision)
{
	double	second_part;
	long	power_part;
	char	*strfir_part;
	char	*strsec_part;
	char	*result;
	int		is_neg;

	is_neg = (f < 0) ? 1 : 0;
	power_part = (long)f;
	second_part = (is_neg) ? f * -1 - (double)power_part * -1
							: f - (double)power_part;
	second_part = second_part * ft_pow(10, precision - 1);
	result = ft_strnew(get_size_nb(power_part) + get_size_nb(second_part)
												+ is_neg);
	strfir_part = ft_itoa(power_part);
	strfir_part[get_size_nb(power_part)] = '.';
	strsec_part = ft_itoa(ft_cast_double_to_long(second_part, precision));
	result = ft_strjoin(strfir_part, strsec_part);
	return (result);
}
