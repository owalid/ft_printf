/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_df.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 06:43:56 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/16 06:53:32 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*option_plus_df(t_output *output, size_t size, char *res, size_t *i)
{
	(void)size;
	if (output->str[0] != '-')
	{
		res[(*i)++] = '+';
		output->size_flag->precision += output->option->point;
	}
	return (res);
}

char		*option_point_df(t_output *output, char *res, size_t *i)
{
	char	*tmp;

	if (output->str[0] == '-')
	{
		while (*i < output->size_flag->precision - (ft_strlen(output->str) - 1))
			res[(*i)++] = '0';
		res = ft_strjoin_char('-', res, 1);
		tmp = ft_itoa_base(ft_atoi(output->str) * -1, 10);
		res = ft_strjoin_free(res, tmp);
	}
	else
	{
		while (*i < output->size_flag->precision - ft_strlen(output->str))
			res[(*i)++] = '0';
	}
	return (res);
}

char		*option_zero_df(t_output *output, char *res, size_t *i)
{
	char	*tmp;

	if (output->str[0] == '-')
	{
		while (*i < output->minsize - (ft_strlen(output->str)))
			res[(*i)++] = '0';
		res = ft_strjoin_char('-', res, 1);
		tmp = ft_itoa(ft_atoi(output->str) * -1);
		res = ft_strjoin_free(res, tmp);
	}
	else
	{
		while (*i < output->minsize - ft_strlen(output->str))
			res[(*i)++] = '0';
	}
	return (res);
}

char		*option_space_df(t_output *output, char *res)
{
	char	*tmp;

	if (res[0] != '-' || output->minsize > ft_strlen(res))
	{
		if (output->minsize > ft_strlen(res))
			res = ft_add_blank(output, res, 0);
		else
		{
			tmp = ft_str_from_char(' ');
			res = ft_strjoin_free(tmp, res);
		}
	}
	return (res);
}
