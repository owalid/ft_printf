/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:40:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/06 19:21:36 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_verif_base(int base)
{
	if (base >= 2 && base <= 16)
		return (1);
	return (0);
}

static int				get_second_nb(intmax_t a)
{
	return (a % 10);
}

static int				nb_ofnb(intmax_t nb, int base)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

static void				is_neg(intmax_t *nb, int *neg, int *size, int base)
{
	if (*nb < 0)
	{
		if (base == 10)
		{
			*neg = 1;
			*size += 1;
		}
		*nb *= -1;
	}
	*size += nb_ofnb(*nb, base) + 1;
}

char					*ft_itoa_base(intmax_t nb, int base)
{
	char				*result;
	int					size;
	int					neg;

	neg = 0;
	size = 0;
	if (!ft_verif_base(base))
		return (ft_strdup(""));
	if (nb == -9223372036854775808)
		return (strdup("-9223372036854775808"));
	is_neg(&nb, &neg, &size, base);
	if ((result = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result[--size] = '\0';
	while (size--)
	{
		if (nb % base > 9)
			result[size] = 65 + get_second_nb(nb % base);
		else
			result[size] = nb % base + '0';
		nb /= base;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
