/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_sc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:31:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:13:28 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_sc(t_output *out, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!out->option->point && !out->option->zero)
		return (out->str);
	if (out->option->point && out->size_flag->precision < ft_strlen(out->str))
	{
		if (!(result = ft_strsub(out->str, 0, out->size_flag->precision)))
			ft_err(1);
		ft_strdel(&out->str);
		return (result);
	}
	if (!(result = ft_strnew(size)))
		ft_err(1);
	if (out->option->zero && out->minsize > ft_strlen(out->str)
			&& !out->option->min)
	{
		while (i < out->minsize - ft_strlen(out->str))
			result[i++] = '0';
	}
	if (!(result = ft_strjoin_free(result, out->str)))
		ft_err(1);
	return (result);
}

int			ft_formater_sc(t_output *out, int opt)
{
	size_t	i;
	size_t	size;

	if (out->size_flag->no_prec)
		ft_is_null(out);
	out->minsize = (out->minsize <= 0 && !out->size_flag->precision)
									? ft_strlen(out->str) : out->minsize;
	size = out->minsize + out->option->space + out->option->plus;
	size = (size == 0) ? 1 : size;
	i = 0;
	if (ft_strlen(out->str) < size)
	{
		out->str = ft_formater_with_option_sc(out, size);
		if (out->option->min == 1 && out->minsize > ft_strlen(out->str))
			out->str = ft_add_blank(out, out->str, 1);
	}
	else
		out->str = ft_formater_with_option_sc(out, ft_strlen(out->str));
	if ((out->option->space == 1 && !out->option->plus)
			|| (out->minsize > ft_strlen(out->str)))
		out->str = ft_add_blank(out, out->str, 0);
	send_char(out->str, opt, &i);
	return ((out->size_flag->no_prec) ? 0 : i);
}
