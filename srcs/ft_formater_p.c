/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:33:06 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 08:29:16 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_p_bis(t_output *out, size_t size,
												char **result, char **tmp)
{
	if (out->option->zero && !out->option->min && (ft_strlen(out->str) < size
			|| out->minsize > ft_strlen(out->str)))
	{
		if (ft_strcmp(out->str, "0") == 0)
			*result = option_point_p(out, *result, out->minsize - 2);
		else
			*result = option_point_p(out, *result, out->minsize - 1);
		if (out->str[0] == '-')
			return (*result);
	}
	*result = ft_strjoin_free(*tmp, *result);
	out->str = ft_strjoin_free(*result, out->str);
	return (out->str);
}

char		*ft_formater_with_option_p(t_output *out, size_t size)
{
	char	*result;
	char	*tmp;

	tmp = ft_strdup("0x");
	if (!one_option(out))
	{
		out->str = ft_strjoin_free(tmp, out->str);
		return (out->str);
	}
	result = ft_strnew(size);
	if (out->option->point
			&& ft_strlen(out->str) <= out->size_flag->precision)
	{
		result = option_point_p(out, result, out->size_flag->precision);
		if (out->str[0] == '-')
			return (result);
	}
	return (ft_formater_with_option_p_bis(out, size, &result, &tmp));
}

int			ft_formater_p(t_output *out, int opt)
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
		out->str = ft_formater_with_option_p(out, size);
		if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
			out->str = ft_add_blank(out, out->str, 1);
	}
	else
		out->str = ft_formater_with_option_p(out, ft_strlen(out->str));
	if (out->minsize > ft_strlen(out->str) && !out->option->min)
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return (i);
}
