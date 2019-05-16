/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supdigit_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:59:48 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 07:59:49 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_supdigit_at(int nb, int rank)
{
	nb -= ft_pow(get_digit_at(nb, rank), rank);
	return (nb);
}
