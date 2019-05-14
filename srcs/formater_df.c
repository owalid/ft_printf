#include "ft_printf.h"

char	*ft_formater_with_option_df(t_output *output, size_t size)
{
	char 	*result;
	size_t	i;

	i = 0;
	if (!one_option(output))
		return (output->str);
	result = ft_strnew(size);
	if (output->option->plus)
		result = option_plus_df(output, output->minsize, result, &i);

	if (output->option->point && ft_strlen(output->str) <= output->size_flag->precision
						&& (!output->is_null) && output->conv_type != 'y')
	{
		result = option_point_df(output, result, &i);
		if (output->str[0] == '-')
		{
			ft_strdel(&output->str);
			return (result);
		}
	}
	if (output->option->zero && !output->option->point && !output->option->min
			&& (ft_strlen(output->str) < size || output->minsize > ft_strlen(output->str)))
	{
		result = option_zero_df(output, result, &i);
		if (output->str[0] == '-')
		{
			ft_strdel(&output->str);
			return (result);
		}
	}
	output->str = ft_strjoin_free(result, output->str);
	return (output->str);
}

int		ft_formater_df(t_output *output, int opt)
{
	size_t	i;
	int		size;

	if (ft_strcmp(output->str, "0") == 0 && output->size_flag->no_prec && !output->option->hash)
		ft_is_null(output);
	size = output->minsize + output->option->space + output->option->plus;
	i = 0;
	if (ft_strlen(output->str) < output->minsize)
	{
		output->str = ft_formater_with_option_df(output, size);		
		if (output->option->min == 1 && output->minsize > ft_strlen(output->str))
			output->str = ft_add_blank(output, output->str, 1);
	}
	else
		output->str = ft_formater_with_option_df(output, ft_strlen(output->str));
	if (output->option->space == 1 && !output->option->plus)
		output->str = option_space_df(output, output->str);
	if (output->minsize > ft_strlen(output->str))
		output->str = ft_add_blank(output, output->str, 0);

	send_char(output->str, opt, &i);
	return (i);
}