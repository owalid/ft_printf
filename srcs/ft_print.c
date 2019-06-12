/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 07:02:04 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/06/12 23:37:16 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_char(char c, int opt, t_output *out)
{
	static char		str[4096];
	static int		size;
	(void)out;
	
	if (out->conv_type == 'c' && c == 0 && out->is_null)
	{
		write(1, str, size);
		str[0] = '\0';
		size = 0;
		write(1, "\0", 1);
	}
	if (ft_strlen(str) == 0)
		size = 0;
	if ((size == 4096 || opt) && *str)
	{
		write(1, str, size);
		str[0] = '\0';
		size = 0;
	}
// else if (out->conv_type == 'c' && out->is_null)
// 	{
// 		if (out->str[0] != '\0')
// 			write(1, str, size);
// 		else
// 			write(1, "\0", 1);
// 		size = 0;
// 	}
	else
	{
		str[size] = c;
		size++;
	}
}

int			ft_formater(t_output *output, int opt)
{
	if (output->conv_type == 'd' || output->conv_type == 'f'
			|| output->conv_type == 'i')
		return (ft_formater_df(output, opt));
	else if (output->conv_type == 's')
		return (ft_formater_sc(output, opt));
	else if (output->conv_type == 'x' || output->conv_type == 'X')
		return (ft_formater_xx(output, opt));
	else if (output->conv_type == 'p')
		return (ft_formater_p(output, opt));
	else if (output->conv_type == 'u' || output->conv_type == 'U')
		return (ft_formater_u(output, opt));
	else if (output->conv_type == 'o')
		return (ft_formater_o(output, opt));
	else if (output->conv_type == 'c')
		return (ft_formater_c(output, opt));
	else
		return (ft_formater_df(output, opt));
}
