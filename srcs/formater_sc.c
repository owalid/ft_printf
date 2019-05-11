#include "ft_printf.h"

char	*ft_formater_with_option_c(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	size = (output->size_flag->precision && !output->minsize) ? 0 : size; 
	result = ft_strnew(size);
	if (output->minsize)
		while (i < size)
			result[i++] = ' ';
	else if (output->option->zero)
		while (i < size)
			result[i++] = '0';
	if (!output->option->min)
		result[size - 1] = output->str[0];
	else
		result[0] = output->str[0];
	return (result);
}

char	*ft_formater_with_option_s(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	result = ft_strnew(size);
	if (output->option->point && output->size_flag->precision < ft_strlen(output->str))
	{
		result = ft_strsub(output->str, 0, output->size_flag->precision);
		return (result);
	}
	if (output->option->zero && output->minsize > ft_strlen(output->str) && !output->option->min)
	{
		while (i < output->minsize - ft_strlen(output->str))
			result[i++] = '0';
	}
	result = ft_strjoin(result, output->str);
	return (result);
}

int		ft_formater_sc(t_output *output, int opt)
{
	char 	*result;
	size_t	i;
	size_t	size;
	
<<<<<<< HEAD
	result = NULL;
	if (!output->str)
=======
	if (!output->str || output->size_flag->no_prec)
>>>>>>> origin/owalid
	{
		output->is_null = 1;
		output->str = ft_strdup("(null) du ft_formater_sc");
	}
<<<<<<< HEAD
	output->option->space == 1 ? output->option->plus = 0 : 0;
=======
	output->minsize = (output->minsize <= 0 && !output->size_flag->precision) ? ft_strlen(output->str) : output->minsize;
>>>>>>> origin/owalid
	size = output->minsize + output->option->space + output->option->plus;
	if (size < 0)
		size = 1;
	i = 0;
<<<<<<< HEAD
	if (output->conv_type == 'c')
	{
		result = ft_formater_with_option_sc(output, size);
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
		{
			tmp = ft_strnew(output->minsize - ft_strlen(result));
			while (i < output->minsize - ft_strlen(result))
				tmp[i++] = ' ';
			if (i != 0)
				result = ft_strjoin(result, tmp);
			ft_strdel(&tmp);	
		}
		else
			result = ft_formater_with_option_s(output, ft_strlen(output->str));
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
	i = -1;
	while (result[++i])
		add_char(result[i], opt);
=======
	if (ft_strlen(output->str) < size)
	{
		result = ft_formater_with_option_sc(output, size);
		if (output->option->min == 1 && output->minsize > ft_strlen(result))
			result = ft_add_blank(output, result, 1);
	}
	else
		result = ft_formater_with_option_sc(output, ft_strlen(output->str));
	if (output->option->space == 1  && !output->option->plus)
		result = ft_add_blank(output, result, 0);
	if (output->minsize > ft_strlen(result))
		result = ft_add_blank(output, result, 0);
	send_char(result, opt, &i);
	// printf("result => %s", result);
	if (output->size_flag->no_prec)
		i = 0;
>>>>>>> origin/owalid
	return (i);
}
