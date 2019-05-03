#include "ft_printf.h"

char	*ft_formater_with_option_sc(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->point)
	{
		if (output->size_flag->precision < ft_strlen(output->str))
		{
			result = ft_strsub(output->str, 0, output->size_flag->precision);
			return (result);
		}
	}
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_sc(t_output *output, int opt)
{
	char 	*result;
	char	*tmp;
	size_t	i;
	int		size;
	
	if (!output->str)
	{
		output->is_null = 1;
		output->str = ft_strdup("(null)");
	}
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		result = ft_formater_with_option_sc(output, size);
		// printf("%zu\n", ft_strlen(result));
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
		result = ft_formater_with_option_sc(output, ft_strlen(output->str));
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
		else
		{
			tmp = ft_str_from_char(' ');
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
