#include "ft_printf.h"

char	*ft_formater_with_option_df(t_output *output, size_t size)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	// size_t	tmp;

	i = 0;
	result = ft_strnew(size);
	// printf("\ns => %s\n\n", output->str);
	if (output->option->plus)
	{
		if (ft_strlen(output->str) < size && !output->option->min)
		{
			while (i < size - ft_strlen(output->str))
				result[i++] = ' ';
		}
		if (output->str[0] != '-')
		{
			result[i++] = '+';
			output->size_flag->precision += output->option->point;
		}
	}

	if (output->option->point && ft_strlen(output->str) <= output->size_flag->precision)
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
			while (i < output->size_flag->precision - ft_strlen(output->str))
				result[i++] = '0';
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
	
	if (output->option->hash && ft_strlen(output->str) < size)
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

int		ft_formater_df(t_output *output, int opt)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	int		size;
	
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_df(output, size);		
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
		result = ft_formater_with_option_df(output, ft_strlen(output->str));
	if (output->option->space == 1 && !output->option->plus && (!output->option->min || output->option->point))
	{
		if (result[0] != '-' || output->minsize > ft_strlen(result))
		{
			if (output->minsize > ft_strlen(result))
			{
				i = 0;
				tmp = ft_strnew(output->minsize - ft_strlen(result));
				while (i < output->minsize - ft_strlen(result))
					tmp[i++] = ' ';
				if (i != 0)
					result = ft_strjoin(tmp, result);
				ft_strdel(&tmp);
			}
			else
			{
				tmp = ft_str_from_char(' ');
				result = ft_strjoin(tmp, result);
				ft_strdel(&tmp);
			}
		}
	}
	if (output->minsize > ft_strlen(result))
	{
		i = 0;
		tmp = ft_strnew(output->minsize - ft_strlen(result));
		while (i < output->minsize - ft_strlen(result))
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
	return (i);
}