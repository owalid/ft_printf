/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:36:49 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/04/30 12:13:54 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			get_size_nb(int nb)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
