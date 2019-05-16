/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:53:59 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:22:22 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*option_hash_o(t_output *output, size_t size, char *res, size_t *i)
{
	if (output->conv_type == 'x' || output->conv_type == 'X')
	{
		res[*i] = '0';
		res[++(*i)] = 'x';
	}
	if (output->conv_type == 'o')
		res[*i] = '0';
	(*i)++;
	if (output->option->zero && !output->option->min
			&& (ft_strlen(output->str) < size
			|| output->minsize > ft_strlen(output->str)) && !output->is_null)
		res = option_zero_df(output, res, &(*i));
	if (!(res = ft_strjoin_free(res, output->str)))
		ft_err(1);
	return (res);
}
