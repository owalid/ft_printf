/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:58:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 07:58:50 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_supdigit(int nb, int size)
{
	int		size_nb;

	size_nb = get_size_nb(nb);
	while (size && size_nb)
	{
		nb /= 10;
		size--;
		size_nb--;
	}
	return (nb);
}
