/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_df.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:39:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 08:22:58 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_df_bis(t_output *out, size_t size,
												char **result, size_t *i)
{
	if (out->option->zero && !out->option->point && !out->option->min
		&& (ft_strlen(out->str) < size
				|| out->minsize > ft_strlen(out->str)))
	{
		*result = option_zero_df(out, *result, i);
		if (out->str[0] == '-')
		{
			ft_strdel(&out->str);
			return (*result);
		}
	}
	out->str = ft_strjoin_free(*result, out->str);
	return (out->str);
}

char		*ft_formater_with_option_df(t_output *out, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (out->option->plus)
		result = option_plus_df(out, out->minsize, result, &i);
	if (out->option->point && ft_strlen(out->str) <= out->size_flag->precision
						&& (!out->is_null) && out->conv_type != 'y')
	{
		result = option_point_df(out, result, &i);
		if (out->str[0] == '-')
		{
			ft_strdel(&out->str);
			return (result);
		}
	}
	return (ft_formater_with_option_df_bis(out, size, &result, &i));
}

int			ft_formater_df(t_output *out, int opt)
{
	size_t	i;
	int		size;

	if (ft_strcmp(out->str, "0") == 0 && out->size_flag->no_prec
			&& !out->option->hash)
		ft_is_null(out);
	size = out->minsize + out->option->space + out->option->plus;
	i = 0;
	if (one_option(out))
	{
		if (ft_strlen(out->str) < out->minsize)
		{
			out->str = ft_formater_with_option_df(out, size);
			if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
				out->str = ft_add_blank(out, out->str, 1);
		}
		else
			out->str = ft_formater_with_option_df(out, ft_strlen(out->str));
	}
	if (out->option->space == 1 && !out->option->plus)
		out->str = option_space_df(out, out->str);
	if (out->minsize > ft_strlen(out->str))
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return (i);
}
