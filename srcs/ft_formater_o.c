/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:23:57 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 08:25:06 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_o_bis(t_output *out, size_t size,
												char **result, size_t *i)
{
	if (out->option->zero && !out->option->min && !out->is_null
		&& (ft_strlen(out->str) < size || out->minsize > ft_strlen(out->str)))
	{
		*result = option_zero_df(out, *result, i);
		if (out->str[0] == '-')
			return (*result);
	}
	if (out->option->hash && ft_strcmp(out->str, "0") != 0)
	{
		out->str = option_hash_o(out, size, *result, i);
		return (out->str);
	}
	out->str = ft_strjoin_free(*result, out->str);
	return (out->str);
}

char		*ft_formater_with_option_o(t_output *out, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!one_option(out))
		return (out->str);
	result = ft_strnew(size);
	if (out->option->point
			&& ft_strlen(out->str) < out->size_flag->precision
			&& !out->is_null)
	{
		result = option_point_df(out, result, &i);
		if (out->str[0] == '-')
			return (result);
	}
	return (ft_formater_with_option_o_bis(out, size, &result, &i));
}

int			ft_formater_o(t_output *out, int opt)
{
	size_t	i;
	int		size;

	if (ft_strcmp(out->str, "0") == 0 && out->size_flag->no_prec
					&& !out->option->hash)
		ft_is_null(out);
	size = out->minsize + out->option->space + out->option->plus;
	i = 0;
	if (ft_strlen(out->str) < out->minsize)
	{
		out->str = ft_formater_with_option_o(out, size);
		if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
			out->str = ft_add_blank(out, out->str, 1);
	}
	else
		out->str = ft_formater_with_option_o(out, ft_strlen(out->str));
	if (out->minsize > ft_strlen(out->str) && !out->option->min)
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return (i);
}
