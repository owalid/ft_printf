#include "ft_printf.h"

char	*ft_formater_with_option_o(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	if (!one_option(output))
		return (output->str);
	result = ft_strnew(size);
	if (output->option->point
			&& ft_strlen(output->str) < output->size_flag->precision
			&& !output->is_null)
	{
		result = option_point_df(output, result, &i);
		if (output->str[0] == '-')
			return (result);
	}
	if (output->option->zero && !output->option->min && !output->is_null
		&& (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		result = option_zero_df(output, size, result, &i);
		if (output->str[0] == '-')
			return (result);
	}
	if (output->option->hash && ft_strcmp(output->str, "0") != 0)
	{
		output->str = option_hash_o(output, size, result, &i);
		return (output->str);
	}
	output->str = ft_strjoin(result, output->str);
	ft_strdel(&result);
	return (output->str);
}

int		ft_formater_o(t_output *output, int opt)
{
	size_t	i;
	int		size;
	
	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec && !output->option->hash)
		ft_is_null(output);
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		output->str = ft_formater_with_option_o(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
			output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_o(output, ft_strlen(output->str));
	if (output->minsize > ft_strlen(output->str) && !output->option->min)
		output->str = ft_add_blank(output, output->str, 0);
	send_char(output->str, opt, &i);
	return (i);
}