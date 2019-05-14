#include "ft_printf.h"

char	*ft_formater_with_option_c(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	size = (output->size_flag->precision && !output->minsize) ? 0 : size; 
	result = ft_strnew(size);
	if (output->minsize)
		while (i < size)
			result[i++] = ' ';
	else if (output->option->zero)
		while (i < size)
			result[i++] = '0';
	if (!output->option->min)
		result[size - 1] = output->str[0];
	else
		result[0] = output->str[0];
	return (result);
}

char	*ft_formater_with_option_s(t_output *output, size_t size)
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
	output->str = ft_strjoin(result, output->str);
	ft_strdel(&result);
	return (output->str);
}

int		ft_formater_sc(t_output *output, int opt)
{
	size_t	i;
	size_t	size;
	
	if (!output->str || output->size_flag->no_prec)
	{
		output->is_null = 1;
		output->str = ft_strdup("(null) du ft_formater_sc");
	}
	output->minsize = (output->minsize <= 0 && !output->size_flag->precision) ? ft_strlen(output->str) : output->minsize;
	size = output->minsize + output->option->space + output->option->plus;
	if (size < 0)
		size = 1;
	i = 0;
	if (ft_strlen(output->str) < size)
	{
		output->str = ft_formater_with_option_sc(output, size);
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
			output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_sc(output, ft_strlen(output->str));
	if (output->option->space == 1  && !output->option->plus)
		output->str = ft_add_blank(output, output->str, 0);
	if (output->minsize > ft_strlen(output->str))
		output->str = ft_add_blank(output, output->str, 0);
	send_char(output->str, opt, &i);
	if (output->size_flag->no_prec)
		i = 0;
	return (i);
}
