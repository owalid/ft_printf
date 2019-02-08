/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:33:52 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/02/08 17:51:15 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_supzero(int nb)
{
	int		size;

	size = get_size_nb(nb);
	while (get_digit_at(nb, size) == 0 && size)
	{
		nb /= 10;
		size--;
	}
	return (nb);
}
