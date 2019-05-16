/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:29:45 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:13:54 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_formater_with_option_u(t_output *out, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!one_option(out))
		return (out->str);
	if (!(result = ft_strnew(size)))
		ft_err(1);
	if (out->option->point && !out->size_flag->no_prec
			&& ft_strlen(out->str) < out->size_flag->precision)
	{
		result = option_point_df(out, result, &i);
		if (out->str[0] == '-')
			return (result);
	}
	if (out->option->zero && !out->option->min
		&& (ft_strlen(out->str) < size || out->minsize > ft_strlen(out->str)))
	{
		result = option_zero_df(out, result, &i);
		if (out->str[0] == '-')
			return (result);
	}
	if (!(out->str = ft_strjoin_free(result, out->str)))
		ft_err(1);
	return (out->str);
}

int		ft_formater_u(t_output *out, int opt)
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
		out->str = ft_formater_with_option_u(out, size);
		if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
			out->str = ft_add_blank(out, out->str, 1);
	}
	else
		out->str = ft_formater_with_option_u(out, ft_strlen(out->str));
	if (out->option->space == 1 && out->minsize > ft_strlen(out->str))
		out->str = ft_add_blank(out, out->str, 0);
	if (out->minsize > ft_strlen(out->str) && !out->option->min)
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return (i);
}
