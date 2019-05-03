/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:38:58 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 10:18:38 by oel-ayad         ###   ########.fr       */
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
<<<<<<< HEAD
			pf_conv(output, format, &i);
			if (format[i] == '\0')
				break ;
			ft_prepare_cond(output, format, i, ap);
=======
			while (!ft_is_conv(format[i]))
			{
				if (format[i] == '.')
				{
					if (!ft_isdigit(format[i + 1]) && format[i + 1] == 'f')
					{
						output->size_flag->no_prec = 1;
					}
					else if (ft_isdigit(format[i + 1]))
					{
						j = i++;
						while (ft_isdigit(format[j++]))
							;
						tmp = ft_strsub(format, i, j);
						output->size_flag->precision = (size_t)ft_atoi(tmp);
						output->option->point = 1;
						if (format[j + 1] != 'f' && format[j + 1] != 's' && ft_is_conv(format[j + 1]))
						{
							if (output->minsize < output->size_flag->precision)
								output->minsize = output->size_flag->precision;
						}
						i = j;
						ft_strdel(&tmp);
					}
				}
				else if (ft_isdigit(format[i]) && format[i] != '0')
				{
					j = i;
					while (ft_isdigit(format[j]))
						j++;
					tmp = ft_strsub(format, i, j);
					output->minsize = (size_t)ft_atoi(tmp);
					i = j - 1;
					ft_strdel(&tmp);
				}
				else
					ft_is_option(format[i], output);
				i++;
			}
			if (format[i] == '%')
				output->str = ft_str_from_char(format[i]);
			else
			{
				output->conv_type = format[i];
				output->str = ft_converter(ap, &i, format, output->size_flag);
			}
>>>>>>> quel merdier
		}
		else
			output->str = ft_str_from_char(format[i]);
		result += ft_formater(output, 0);
<<<<<<< HEAD
	}
	end_parser(output, ap, format, i);
	return (result + ft_formater(output, 1));
=======
		// if (output->option->plus)
	}
	output->str = ft_str_from_char(format[i]);
	ft_init_output(output);
	result += ft_formater(output, 1);
	va_end(ap);
	return (result);

>>>>>>> quel merdier
}
