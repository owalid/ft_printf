#include "ft_printf.h"

char	*ft_formater_with_option_p(t_output *output, size_t size)
{
	char 	*result;
	char	*tmp;
	
	tmp = ft_strdup("0x");
	if (!one_option(output))
	{
		output->str = ft_strjoin_free(tmp, output->str);
		return (output->str);
	}
	result = ft_strnew(size);
	if (output->option->point
			&& ft_strlen(output->str) <= output->size_flag->precision)
	{
		result = option_point_p(output, result, output->size_flag->precision);
		if (output->str[0] == '-')
			return (result);
	}
	if (output->option->zero && !output->option->min &&(ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		if (ft_strcmp(output->str, "0") == 0)
			result = option_point_p(output, result, output->minsize - 2);
		else
		result = option_point_p(output, result, output->minsize - 1);
		if (output->str[0] == '-')
			return (result);
	}
	result = ft_strjoin(tmp, result);
	output->str = ft_strjoin_free(result, output->str);
	return (output->str);
}

int		ft_formater_p(t_output *output, int opt)
{
	size_t	i;
	int		size;
	
	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec && !output->option->hash)
		ft_is_null(output);
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		output->str = ft_formater_with_option_p(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
			output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_p(output, ft_strlen(output->str));
	if (output->minsize > ft_strlen(output->str) && !output->option->min)
		output->str = ft_add_blank(output, output->str, 0);
	send_char(output->str, opt, &i);
	return (i);
}