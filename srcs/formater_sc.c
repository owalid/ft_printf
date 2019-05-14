#include "ft_printf.h"

char	*ft_formater_with_option_sc(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	if (!output->option->point && !output->option->zero)
		return (output->str);
	if (output->option->point && output->size_flag->precision < ft_strlen(output->str))
	{
		result = ft_strsub(output->str, 0, output->size_flag->precision);
		ft_strdel(&output->str);
		return (result);
	}
	result = ft_strnew(size);
	if (output->option->zero && output->minsize > ft_strlen(output->str) && !output->option->min)
	{
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = '0';
	}
	result = ft_strjoin_free(result, output->str);
	return (result);
}

int		ft_formater_sc(t_output *output, int opt)
{
	size_t	i;
	size_t	size;
	

	if (output->size_flag->no_prec)
	{
		output->is_null = 1;
		ft_strclr(output->str);
	}
			// exit(1);
	output->minsize = (output->minsize <= 0 && !output->size_flag->precision) ? ft_strlen(output->str) : output->minsize;
	size = output->minsize + output->option->space + output->option->plus;
	size = (size == 0) ? 1 : size;
	i = 0;
	if (ft_strlen(output->str) < size)
	{
		output->str = ft_formater_with_option_sc(output, size);
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
			output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_sc(output, ft_strlen(output->str));
	if ((output->option->space == 1 && !output->option->plus)
			|| (output->minsize > ft_strlen(output->str)))
		output->str = ft_add_blank(output, output->str, 0);
	send_char(output->str, opt, &i);

	i = (output->size_flag->no_prec) ? 0 : i;
	return (i);
}
