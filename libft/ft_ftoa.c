/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 00:25:19 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//////////////////////
#include <stdio.h>
//////////////////////

long long		ft_cast_double_to_long(double nbr)
{
	long long	cast_long;

	cast_long = (long long)nbr;
	if (((nbr - (long long)cast_long) * 10) > 5)
		return (cast_long + 1);
	else
		return (cast_long);
}

char		*ft_nitoa(char *result, long long part, long long n, int *i)
{
	long long		nb;

	nb = ft_pow(10, n - 1);
	while (nb)
	{
		result[(*i)++] = (part / nb) + '0';
		part %= nb;
		nb /= 10;
	}
	return (result);
}

char			*ft_ftoa(double f, size_t precision)
{
	long double	second_part;
	long long	first_part;
	char		*result;
	int			is_neg;
	int			i;

	is_neg = (f < 0) ? 2 : 1;
	first_part = (long long)f;
	if (precision <= 0)
	{
		result = ft_itoa(first_part);
		if (is_neg == 2 && first_part == 0)
			result = ft_strjoin_char('-', result, 1);
		return (result);
	}
	second_part = f - (long double)first_part;
	if (is_neg == 2)
	{
		first_part *= -1;
		second_part *= -1;
	}
	second_part *= ft_pow(10, precision);
	result = ft_strnew(get_size_nb(first_part) + precision
												+ is_neg);
	i = 0;
	if (f < 0)
		result[i++] = '-';
	result = ft_nitoa(result, first_part, get_size_nb(first_part), &i);
	result[i++] = '.';
	second_part = ft_cast_double_to_long(second_part);
	result = ft_nitoa(result, second_part, precision, &i);
	return (result);
}