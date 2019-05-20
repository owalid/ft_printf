/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:56:12 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/20 13:21:15 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_add_blank(t_output *output, char *result, int opt)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (output->minsize - ft_strlen(output->str) >= 1)
		if (!(tmp = ft_strnew(output->minsize - ft_strlen(result))))
			ft_err(1);
	while (i < output->minsize - ft_strlen(result))
		tmp[(i)++] = ' ';
	if (i != 0)
	{
		if (result[0] == '\0')
		{
			ft_strcpy(result, tmp);
			result[i - 1] = '\0';
		}
		else
			result = (opt == 1) ? ft_strjoin_free(result, tmp)
								: ft_strjoin_free(tmp, result);
	}
	if (!result)
		ft_err(1);
	printf("RESULT: |%s|\n", result);
	return (result);
}

int			send_char(t_output *out, int opt, size_t *i)
{
	if (out->conv_type == 'c' && out->is_null)
		add_char(0, opt, out);
	if ((opt == 1 && !*out->str))
		add_char(0, opt, out);
	*i = -1;
	while (out->str[++(*i)])
	{
		add_char(out->str[*i], opt, out);
	}
	ft_strdel(&out->str);
	return ((out->conv_type == 'c' && out->is_null) ? ((int)*i) + 1 : ((int)*i));
}

void		ft_is_null(t_output *output)
{
	if (output->conv_type != 's' && output->conv_type != 'c')
	{
		output->is_null = 1;
		if (!output->option->plus && !output->option->min
			&& !output->option->point && !output->size_flag->no_prec)
		{
			if (!(output->str = ft_strdup("(null)")))
				ft_err(1);
		}
		else if (output->conv_type != 'f' && output->conv_type != 'x')
			ft_strclr(output->str);
	}
	else
	{
		output->is_null = 1;
		ft_strclr(output->str);
	}
}

int			is_no_prec(const char *format, int i)
{
	if ((!ft_isdigit(format[i + 1])
				&& (format[i + 1] == 'f' || format[i + 1] == 'd'
					|| format[i + 1] == 'i' || format[i + 1] == 'u'
					|| format[i + 1] == 'x' || format[i + 1] == 'X'
					|| format[i + 1] == 'o' || format[i + 1] == 'p'
					|| format[i + 1] == 's')))
		return (1);
	else if ((format[i + 1] == '0'
				&& (format[i + 2] == 'f' || format[i + 2] == 'd'
					|| format[i + 2] == 'i' || format[i + 2] == 'u'
					|| format[i + 2] == 'x' || format[i + 2] == 'X'
					|| format[i + 2] == 'o' || format[i + 2] == 'p'
					|| format[i + 2] == 's')))
		return (2);
	return (0);
}

int			one_option(t_output *out)
{
	return ((out->option->min || out->option->space
				|| out->option->plus || out->option->hash
				|| out->option->point || out->option->zero));
}
