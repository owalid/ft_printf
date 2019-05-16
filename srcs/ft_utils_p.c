/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:55:17 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:23:43 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*option_point_p(t_output *output, char *result, size_t size)
{
	char	*tmp;
	char	*min;
	char	*tmp2;
	size_t	i;

	i = 0;
	if (output->str[0] == '-')
	{
		if (!(min = ft_strdup("-"))
				|| !(tmp2 = ft_strdup("0x")))
			ft_err(1);
		while (i < size - (ft_strlen(output->str) - 1))
			result[i++] = '0';
		if (!(result = ft_strjoin_free(min, result))
				|| !(tmp = ft_itoa(ft_atoi(output->str) * -1))
				|| !(result = ft_strjoin_free(tmp2, result))
				|| !(result = ft_strjoin_free(result, tmp)))
			ft_err(1);
	}
	else
	{
		while (i < size - (ft_strlen(output->str)))
			result[i++] = '0';
	}
	return (result);
}
