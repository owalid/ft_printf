/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:40:42 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/11 22:57:39 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_verif_base(int base)
{
	if (base >= 2 && base <= 16)
		return (1);
	return (0);
}

static int				get_second_nb(unsigned long long a)
{
	return (a % 10);
}

static int				nb_ofnb(unsigned long long nb, int base)
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

static unsigned long long		is_neg(long long *nb, int *neg, int *size, int base)
{
	unsigned long long	nbr;

	if (*nb < 0)
	{
		if (base == 10)
		{
			*neg = 1;
			*size += 1;
		}
		nbr = *nb * -1;
	}
	else
		nbr = *nb;
	*size += nb_ofnb(nbr, base) + 1;
	return (nbr);
}

char					*ft_itoa_base(long long nb, int base)
{
	char				*result;
	int					size;
	int					neg;
	unsigned long long	nbr;

	neg = 0;
	size = 0;
	if (!ft_verif_base(base))
		return (ft_strdup(""));
	nbr = is_neg(&nb, &neg, &size, base);
	if ((result = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	result[--size] = '\0';
	while (size--)
	{
		if (nbr % base > 9)
			result[size] = 65 + get_second_nb(nbr % base);
		else
			result[size] = nbr % base + '0';
		nbr /= base;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
