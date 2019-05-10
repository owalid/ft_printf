#include "ft_printf.h"

char	*ft_formater_with_option_sc(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->point && output->size_flag->precision < ft_strlen(output->str))
	{
		result = ft_strsub(output->str, 0, output->size_flag->precision);
		return (result);
	}
	if (output->option->zero && output->minsize > ft_strlen(output->str) && !output->option->min)
	{
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = '0';
	}
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_sc(t_output *output, int opt)
{
	char 	*result;
	size_t	i;
	int		size;
	
	if (!output->str)
	{
		output->is_null = 1;
		// output->str = ft_strdup("(null)");
	}
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_sc(output, size);
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
			result = ft_add_blank(output, result, 1);
	}
	else
		result = ft_formater_with_option_sc(output, ft_strlen(output->str));
	if (output->option->space == 1)
		result = ft_add_blank(output, result, 0);
	if (output->minsize > ft_strlen(result))
		result = ft_add_blank(output, result, 0);
	send_char(result, opt, &i);
	return (i);
}
