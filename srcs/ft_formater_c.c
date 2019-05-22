/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formater_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:30:11 by thdervil          #+#    #+#             */
/*   Updated: 2019/05/22 14:19:01 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_formater_with_option_c(t_output *out)
{
	char	*result;
	size_t	i;

	if (!out->option->zero || out->option->min || !out->minsize)
		return (out->str);
	i = 0;
	result = ft_strnew(out->minsize);
	while (i < out->minsize - 1)
		result[i++] = '0';
	result = ft_strjoin_free(result, out->str);
	return (result);
}

int			ft_formater_c(t_output *out, int opt)
{
	size_t	i;
	int		size;

	size = out->minsize;
	i = 0;
	out->str = ft_formater_with_option_c(out);
	if (out->option->min && out->minsize > ft_strlen(out->str)) 
		out->str = ft_add_blank(out, out->str, 1);
	if (out->minsize > ft_strlen(out->str))
		out->str = ft_add_blank(out, out->str, 0);
	return (send_char(out, opt, &i));
}
