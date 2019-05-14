/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:20:18 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/14 12:31:19 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long		ft_pow(int nb, int power)
{
	long long		result;

	result = nb;
	if (!power)
		return (1);
	if (power == 1)
		return (nb);
	while (--power)
		result *= nb;
	return (result);
}
