#include "ft_printf.h"

char	*ft_formater_with_option_o(t_output *output, size_t size)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	// size_t	tmp;

	i = 0;
	result = ft_strnew(size);
	// printf("size=> %zu\n", size);
	// printf("\nminsize=> %zu\n", output->minsize);

	if (output->option->point && ft_strlen(output->str) < output->size_flag->precision)
	{
		if (output->str[0] == '-')
		{
			tmp = ft_strnew(output->size_flag->precision);
			while (i < output->size_flag->precision - (ft_strlen(output->str) - 1))
				result[i++] = '0';
			result = ft_strjoin("-", result);
			tmp = ft_itoa(ft_atoi(output->str) * -1);
			result = ft_strjoin(result, tmp);
			ft_strdel(&tmp);
			return(result);
		}
		else
		{
		//  printf("ici i=> %zu\n", output->size_flag->precision);
		//  printf("ici i=> %s\n", output->str);
			while (i < output->size_flag->precision - ft_strlen(output->str))
			{
				result[i++] = '0';
				// printf("i => %zu", i);
			}
		}
	}

	if (output->option->zero && (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		if (output->str[0] == '-')
		{
			tmp = ft_strnew(output->minsize);
			while (i < output->minsize - (ft_strlen(output->str)))
				result[i++] = '0';
			result = ft_strjoin("-", result);
			tmp = ft_itoa(ft_atoi(output->str) * -1);
			result = ft_strjoin(result, tmp);
			ft_strdel(&tmp);
			return(result);
		}
		else
		{
			while (i < size - ft_strlen(output->str))
				result[i++] = '0';
		}
	}

	if (output->option->hash && ft_strcmp(output->str, "0") != 0)
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
	if (!result)
		return (output->str);
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_o(t_output *output, int opt)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	int		size;
	
	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec == 1)
	{
		output->is_null = 1;
		if (!output->option->plus && !output->option->min)
			output->str = ft_strdup("(null)");
		else
			output->str = ft_strdup("");
	}
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_o(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
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
		result = ft_formater_with_option_o(output, ft_strlen(output->str));
	if (output->minsize > ft_strlen(result) && !output->option->min)
	{
		i = 0;
		tmp = ft_strnew(output->minsize  - ft_strlen(result));
		while (i < output->minsize  - ft_strlen(result))
			tmp[i++] = ' ';
		if (i != 0)
			result = ft_strjoin(tmp, result);
		ft_strdel(&tmp);
	}
	if (opt == 1 && !result[0])
		add_char(0, opt);
	i = -1;
	while (result[++i])
		add_char(result[i], opt);
	ft_strdel(&result);
	return ((!output->is_null || output->option->plus || output->option->min)
				? i : 0);
}