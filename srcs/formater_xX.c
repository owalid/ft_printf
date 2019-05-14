#include "ft_printf.h"

char	*ft_formater_with_option_xX(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->point && ft_strlen(output->str) <= output->size_flag->precision)
	{
		result = option_point_df(output, result, &i);
		if (output->str[0] == '-')
			return (result);
	}

	if (output->option->hash && ft_strcmp(output->str, "0") != 0 && !output->is_null)
	{
		result = option_hash_o(output, size, result, &i);
		return (result);
	}
	if (output->option->zero && !output->option->min && (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)) && !output->is_null)
	{
		result = option_zero_df(output, result, &i);
		if (output->str[0] == '-')
			return (result);
	}
	if (!*result)
	{
		ft_strdel(&result);
		return (output->str);
	}
	if (!output->option->hash || output->option->zero)
	{
		output->str = ft_strjoin_free(result, output->str);
		return (output->str);
	}
	return (result);
}

int		ft_formater_xX(t_output *output, int opt)
{
	size_t	i;
	int		size;
	
	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec)
	{
		output->is_null = 1;
		ft_strclr(output->str);
	}
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		output->str = ft_formater_with_option_xX(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
				output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_xX(output, ft_strlen(output->str));
	if (output->minsize > ft_strlen(output->str) && !output->option->min)
		output->str = ft_add_blank(output, output->str, 0);
	send_char(output->str, opt, &i);
	return (i);
}