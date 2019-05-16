/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:43:02 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 08:39:17 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prepare_for_y(t_output *output, const char *format, int i)
{
	output->option->space = 0;
	output->option->plus = 0;
	output->size_flag->precision = 0;
	output->conv_type = 'y';
	output->str = ft_str_from_char(format[i]);
}

void	ft_prepare(t_output *output, const char *format, int i, va_list ap)
{
	output->conv_type = format[i];
	output->str = ft_converter(ap, &i, format, output);
}

void	ft_prepare_cond(t_output *output, const char *format, int i, va_list ap)
{
	if (ft_is_conv(format[i]) && format[i] != '%')
		ft_prepare(output, format, i, ap);
	else
		ft_prepare_for_y(output, format, i);
}
