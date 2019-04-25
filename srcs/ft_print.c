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

void	ft_formater(t_output *output, int opt)
{
	char 	*result;
	size_t	i;


	
	if (ft_strlen(output->str) < output->minsize)
	{

		result = ft_strnew(ft_strlen(output->str));
	}
	else
	{
		result = ft_strnew(output->minsize);
		if (output->option->min)
		{
			i = ft_strlen(output->str);
			while (i < output->minsize)
				result[i++] = ' ';
		}
		if (output->option->plus)
		{
			i = 0;
			while (i < output->minsize - ft_strlen(output->str))
				result[i++] = ' ';
			if (output->str[0] != '-' && !(output->option->space))
				result[i] = '+';
		}
		if (output->option->zero)
		{
			i = 0;
			while (i < output->minsize - ft_strlen(output->str))
				result[i++] = '0';
		}
		if (output->option->space)
		{
			i = 0;
			while (i < output->minsize - ft_strlen(output->str))
				result[i++] = ' ';
		}
		if (output->option->hash)
		{
			if (output->conv_type == 'x' || output->conv_type == 'X')
			{
				result[i] = '0';
				result[i++] = 'x';
			}
			if (output->conv_type == 'o')
				result[i] = '0';
		}
	}
	result = ft_strjoin(result, output->str);
	i = -1;
	while (result[++i])
		add_char(result[i], opt);
}
