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

char	*ft_formater_with_option(t_output *output)
{
	char 	*result;
	size_t	i;

	result = ft_strnew(output->minsize);
	if (output->option->min == 1)
	{
		i = ft_strlen(output->str);
		while (i < output->minsize)
			result[i++] = ' ';
		result = ft_strjoin(output->str, result);
	}
	if (output->option->plus == 1)
	{
		i = 0;
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = ' ';
		if (output->str[0] != '-' && !(output->option->space))
			result[i] = '+';
		result = ft_strjoin(result, output->str);
	}
	if (output->option->zero == 1)
	{
		i = 0;
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = '0';
		result = ft_strjoin(result, output->str);
	}
	if (output->option->space == 1)
	{
		i = 0;
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = ' ';
		result = ft_strjoin(result, output->str);
	}
	if (output->option->hash == 1)
	{
		if (output->conv_type == 'x' || output->conv_type == 'X')
		{
			result[i] = '0';
			result[i++] = 'x';
		}
		if (output->conv_type == 'o')
			result[i] = '0';
		result = ft_strjoin(result, output->str);
	}
	else
	{
		i = 0;
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = ' ';
		result = ft_strjoin(result, output->str);
	}
	return (result);
}

void	ft_formater(t_output *output, int opt)
{
	char 	*result;
	size_t	i;

	if (ft_strlen(output->str) < output->minsize)
		result = ft_formater_with_option(output);		
	else
		result = ft_strdup(output->str);
	i = -1;
	if (opt == 1 && !result[0])
		add_char(0, opt);
	while (result[++i])
		add_char(result[i], opt);
	ft_strdel(&result);
}
