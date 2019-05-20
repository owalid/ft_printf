/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:38:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/20 13:21:18 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format
									, t_output *out)
{
	int		o;

	o = -1;
	while (g_prtfop[++o].id)
	{
		if (g_prtfop[o].id == format[*i])
		{
			if (!(out->str = g_prtfop[o].ft_transform(ap, out)))
				ft_err(1);
			return (out->str);
		}
	}
	out->str = ft_str_from_char(format[*i]);
	return (out->str);
}

int			ft_printf(const char *format, ...)
{
	t_output	output[1];
	va_list		ap;
	int			i;
	int			result;

	va_start(ap, format);
	i = -1;
	result = 0;
	while (format[++i])
	{
		ft_init_output(output);
		if (format[i] == '%')
		{
			i++;
			pf_conv(output, format, &i);
			if (format[i] == '\0')
				break ;
			ft_prepare_cond(output, format, i, ap);
		}
		else
			output->str = ft_str_from_char(format[i]);
		result += ft_formater(output, 0);
	}
	end_parser(output, ap, format, i);
	return (result + ft_formater(output, 1));
}
