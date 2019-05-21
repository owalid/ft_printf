/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:30:11 by thdervil          #+#    #+#             */
/*   Updated: 2019/05/21 16:59:15 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_c(t_output *out)
{
	char	*result;
	size_t	i;

	i = -1;
	if (!out->option->zero)
		return (out->str);
	result = out->is_null ? ft_strnew(out->minsize) : ft_strnew(out->minsize + 1);
	if (out->option->zero && !out->option->min)
	{
		while (++i < ft_strlen(result))
			result[i] = '0';
	}
	out->str = ft_strjoin_free(result, out->str);
	return (out->str);
}

int			ft_formater_c(t_output *out, int opt)
{
	size_t	i;
	int		size;

	size = out->minsize;
	i = 0;
	if (ft_strlen(out->str) < out->minsize && out->str[0] != '\0' && out->option->min == 1 && out->minsize > ft_strlen(out->str))
	{
		if (out->option->min && !out->option->zero)
			out->str = ft_add_blank(out, out->str, 1);
		else
			out->str = ft_formater_with_option_c(out);
	}
	if (out->minsize > ft_strlen(out->str))
		out->str = ft_add_blank(out, out->str, 0);
	return (send_char(out, opt, &i));
}
