#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format, t_sizeflag *flag)
{
	int		o;
	char	*result;
	
	o = -1;
	while (g_prtfop[++o].id)
	{
		if (g_prtfop[o].id == format[*i])
		{
			result = g_prtfop[o].ft_transform(ap, flag);
			return (result);
		}
	}
	result = ft_str_from_char(format[*i]);
	return (result);
}

int         ft_printf(const char *format, ...)
{
	t_output 	output[1];
	t_option    option[1];
    t_sizeflag  flag[1];
	va_list		ap;
	int 		i;
	int			j;
	char		*tmp;

	va_start(ap, format);
	i = -1;
	output->option = option;
    output->size_flag = flag;
	while (format[++i])
	{
		ft_init_output(output);
		if (format[i] == '%')
		{
			i++;
			while (!ft_is_conv(format[i]))
			{
				if (format[i] == '.')
				{
					j = i++;
					while (ft_isdigit(format[j++]));
					tmp = ft_strsub(format, i, j);
					output->size_flag->precision = ft_atoi(tmp);
					i = j - 1;
					ft_strdel(&tmp);
				}
				else if (ft_isdigit(format[i]) && format[i] != '0')
				{
					j = i;
					while (ft_isdigit(format[j]))
						j++;
					tmp = ft_strsub(format, i, j);
					output->minsize = (size_t)ft_atoi(tmp);
					i = j - 1;
					ft_strdel(&tmp);
				}
				else
					ft_is_option(format[i], output);
				i++;
			}
			output->conv_type = format[i];
			output->str = ft_converter(ap, &i, format, output->size_flag);
		}
		else
			output->str = ft_str_from_char(format[i]);
		ft_formater(output, 0);
	}
	ft_init_output(output);
	output->str = ft_str_from_char(format[i]);
	ft_formater(output, 1);
	va_end(ap);
	return (0);

}
