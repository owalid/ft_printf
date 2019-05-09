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
			return(result);
	}

	if (output->option->hash && ft_strcmp(output->str, "0") != 0 && !output->is_null)
	{
		result = option_hash_o(output, size, result, &i);
		return (result);
	}
	if (output->option->zero && !output->option->min && (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)) && !output->is_null)
	{
		result = option_zero_df(output, size, result, &i);
		if (output->str[0] == '-')
			return(result);
	}
	if (!*result)
	{
		return (ft_strdup(output->str));
	}
	if (!output->option->hash)
		result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_xX(t_output *output, int opt)
{
	char 	*result;
	size_t	i;
	int		size;
	
	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec)
	{
		output->is_null = 1;
		output->str = ft_strdup("");
	}
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_xX(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
				result = ft_add_blank(output, result, 1);
	}
	else
		result = ft_formater_with_option_xX(output, ft_strlen(output->str));
	if (output->minsize > ft_strlen(result) && !output->option->min)
		result = ft_add_blank(output, result, 0);
	send_char(result, opt, &i);
	return (i);
}