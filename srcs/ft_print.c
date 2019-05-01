#include "ft_printf.h"

void		add_char(char c, int opt)
{
	static char		str[1024];
	static int		size;

	if (ft_strlen(str) == 0)
		size = 0;
	if (size == 1024 || opt)
	{
		write(1, str, size);
		str[0] = '\0';
		size = 0;
	}
	else
	{
		str[size] = c;
		size++;
	}
}

char	*ft_formater_with_option(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;
	// size_t	tmp;

	i = 0;
	result = ft_strnew(size);
	if (output->option->plus == 1)
	{
		if (ft_strlen(output->str) < size && !output->option->min)
		{
			while (i < size - ft_strlen(output->str))
				result[i++] = ' ';
		}
		if (output->str[0] != '-' && !(output->option->space))
			result[i++] = '+';
	}
	if (output->option->zero && (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		while (i < size - ft_strlen(output->str))
			result[i++] = '0';
	}
	if (output->option->space == 1)
	{
			result[i++] = ' ';
			output->size_flag->precision += output->option->point;
	}
	if (output->option->point && ft_strlen(output->str) < output->size_flag->precision)
	{
		// printf("%zu\n", output->size_flag->precision - ft_strlen(output->str));
		while (i < output->size_flag->precision - ft_strlen(output->str))
			result[i++] = '0';
		// result = ft_strjoin(output->str, result);
		// return (result);
	}
	// if (output->option->min == 1)
	// {
	// 	tmp = i;
	// 	while (i < size - ft_strlen(output->str))
	// 	{
	// 		result[i++] = ' ';
	// 	}
	// 	if (tmp != i)
	// 	{
	// 		result = ft_strjoin(output->str, result);
	// 		return (result);
	// 	}
	// }
	if (output->option->hash == 1 && ft_strlen(output->str) < size)
	{
		if (output->conv_type == 'x' || output->conv_type == 'X')
		{
			result[i] = '0';
			result[++i] = 'x';
		}
		if (output->conv_type == 'o')
			result[i] = '0';
		result = ft_strjoin(result, output->str);
		i++;
		if (ft_strlen(output->str) < size)
		{
			while (i < size - ft_strlen(output->str))
				result[++i] = ' ';
		}
		return (result);
	}
	// if (ft_strlen(output->str) < size && i < size)
	// {
	// 	while (i < size - ft_strlen(output->str))
	// 		result[i++] = ' ';
	// }
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater(t_output *output, int opt)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	int		size;
	
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option(output, size);		
		if (output->option->min == 1)
		{
			tmp = ft_strnew(output->minsize - ft_strlen(result));
			while (i < output->minsize - ft_strlen(result))
				tmp[i++] = ' ';
			if (i != 0)
				result = ft_strjoin(result, tmp);
			ft_strdel(&tmp);
		}
	}
	else
		result = ft_formater_with_option(output, ft_strlen(output->str));
	// if (output->option->space == 1)
	// {
	// 	tmp 
	// 		result[i++] = ' ';
	// }
	// if (output->option->space == 1)
	// 	result = ft_strjoin(" ", result);
	if (opt == 1 && !result[0])
		add_char(0, opt);
	i = -1;
	while (result[++i])
		add_char(result[i], opt);
	ft_strdel(&result);
	return (i);
}
