#include "ft_printf.h"

char	*ft_formater_with_option_u(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->plus && ft_strlen(output->str) < size && !output->option->min)
        result = option_plus_df(output,  size, result, &i);
	if (output->option->point && ft_strlen(output->str) <= output->size_flag->precision)
	{
		result = option_point_df(output, result, &i);
		if (output->str[0] == '-')
			return(result);
	}

	if (output->option->zero && (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		result = option_zero_df(output, size, result, &i);
		if (output->str[0] == '-')
			return(result);
	}
	if (!result)
		return (output->str);
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_u(t_output *output, int opt)
{
	char 	*result;
	size_t	i;
	int		size;
	
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_u(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
			result = ft_add_blank(output, result, 1);
	}
	else
		result = ft_formater_with_option_u(output, ft_strlen(output->str));
	if (output->option->space == 1 && output->minsize > ft_strlen(result))
        result = ft_add_blank(output, result, 0);
	if (output->minsize > ft_strlen(result) && !output->option->min)
        result = ft_add_blank(output, result, 0);
	send_char(result, opt, &i);
	return (i);
}