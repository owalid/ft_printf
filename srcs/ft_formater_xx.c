/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_xx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:26:41 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:14:52 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_xx_bis(t_output *out, size_t size,
												char **result, size_t *i)
{
	if (out->option->zero && !out->option->min
	&& (ft_strlen(out->str) < size
			|| out->minsize > ft_strlen(out->str))
	&& !out->is_null)
	{
		*result = option_zero_df(out, *result, i);
		if (out->str[0] == '-')
			return (*result);
	}
	if (!*(*result))
	{
		ft_strdel(&(*result));
		return (out->str);
	}
	if (!out->option->hash || out->option->zero)
	{
		if (!(out->str = ft_strjoin_free(*result, out->str)))
			ft_err(1);
		return (out->str);
	}
	return (*result);
}

char		*ft_formater_with_option_xx(t_output *out, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = ft_strnew(size)))
		ft_err(1);
	if (out->option->point && ft_strlen(out->str) <= out->size_flag->precision)
	{
		result = option_point_df(out, result, &i);
		if (out->str[0] == '-')
			return (result);
	}
	if (out->option->hash && ft_strcmp(out->str, "0") != 0 && !out->is_null)
	{
		result = option_hash_o(out, size, result, &i);
		return (result);
	}
	return (ft_formater_with_option_xx_bis(out, size, &result, &i));
}

int			ft_formater_xx(t_output *out, int opt)
{
	size_t	i;
	int		size;

	if (ft_strcmp(out->str, "0") == 0 && out->size_flag->no_prec)
	{
		out->is_null = 1;
		ft_strclr(out->str);
	}
	size = out->minsize + out->option->space + out->option->plus;
	i = 0;
	if (ft_strlen(out->str) < out->minsize)
	{
		out->str = ft_formater_with_option_xx(out, size);
		if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
			out->str = ft_add_blank(out, out->str, 1);
	}
	else
		out->str = ft_formater_with_option_xx(out, ft_strlen(out->str));
	if (out->minsize > ft_strlen(out->str) && !out->option->min)
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return (i);
}
