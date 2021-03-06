/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:07:17 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 07:47:43 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_ofnb(int nb)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void		is_neg(int *nb, int *neg, int *size)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
		*size += 1;
	}
}

char			*ft_itoa(int nb)
{
	char	*result;
	int		i;
	int		size;
	int		neg;

	neg = 0;
	i = 0;
	size = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 2147483647)
		return (ft_strdup("2147483647"));
	is_neg(&nb, &neg, &size);
	size += nb_ofnb((long)nb) + 1;
	if (!(result = ft_strnew(sizeof(char) * size)))
		return (NULL);
	result[--size] = '\0';
	while (size--)
	{
		result[size] += ((nb % 10) + '0');
		nb /= 10;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
