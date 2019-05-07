#include "ft_printf.h"

char	*ft_formater_with_option_u(t_output *output, size_t size)
{
	char 	*result;
	char	*tmp;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->plus)
	{
		if (ft_strlen(output->str) < size && !output->option->min)
		{
			while (i < size - ft_strlen(output->str))
				result[i++] = ' ';
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
	if (!result)
		return (output->str);
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_u(t_output *output, int opt)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	int		size;
	
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_u(output, size);		
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
		result = ft_formater_with_option_u(output, ft_strlen(output->str));
	if (output->option->space == 1)
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
	}
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
	return (i);
}