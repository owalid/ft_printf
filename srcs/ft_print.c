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

	i = 0;
	result = ft_strnew(size);
	if (output->option->min == 1)
	{
		while (i < size)
			result[i++] = ' ';
		result = ft_strjoin(output->str, result);
		return (result);
	}
	if (output->option->plus == 1)
	{
		while (i < size - ft_strlen(output->str))
			result[i++] = ' ';
		if (output->str[0] != '-' && !(output->option->space))
			result[i] = '+';
	}
	if (output->option->zero == 1)
	{
		while (i < size - ft_strlen(output->str))
			result[i++] = '0';
	}
	if (output->option->space == 1)
	{
		while (i < size - ft_strlen(output->str))
			result[i++] = ' ';
	}
	if (output->option->hash == 1)
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
	if (ft_strlen(output->str) < size && i < size)
	{
		while (i < size - ft_strlen(output->str))
			result[i++] = ' ';
	}
	result = ft_strjoin(result, output->str);
	return (result);
}

void	ft_formater(t_output *output, int opt)
{
	char 	*result;
	size_t	i;

	if (ft_strlen(output->str) < output->minsize)
		result = ft_formater_with_option(output, output->minsize);		
	else
		result = ft_formater_with_option(output, ft_strlen(output->str));
	if (opt == 1 && !result[0])
		add_char(0, opt);
	i = -1;
	while (result[++i])
		add_char(result[i], opt);
	ft_strdel(&result);
}
