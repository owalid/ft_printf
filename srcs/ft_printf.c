#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format
									, t_sizeflag *flag)
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
    t_sizeflag	flag[1];
	va_list		ap;
	int 		i;
	int			j;
	int			result;
	char		*tmp;

	va_start(ap, format);
	i = -1;
	output->option = option;
    output->size_flag = flag;
	result = 0;
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
					if (is_no_prec(format, i))
						output->size_flag->no_prec = 1;
					else if (ft_isdigit(format[i + 1]))
					{
						j = i++;
						while (ft_isdigit(format[j++]))
							;
						tmp = ft_strsub(format, i, j);
						output->size_flag->precision = (size_t)ft_atoi(tmp);
						output->option->point = 1;
						if (format[j + 1] != 'f' && format[j + 1] != 's' && ft_is_conv(format[j + 2]))
						{
							if (output->minsize < output->size_flag->precision)
								output->minsize = output->size_flag->precision;
						}
						i = j;
						ft_strdel(&tmp);
					}
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
				else if (ft_is_opt(format[i]))
					ft_is_option(format[i], output);
				else
					break;
				i++;
			}
			if (format[i] == '\0')
				break;
			else if (format[i] == '%' && format[i + 1] == '\0')
			{
				output->conv_type = 's';
				output->str = ft_str_from_char(format[i]);
			}
			else if (ft_is_conv(format[i]) && format[i] != '%')
			{
				output->conv_type = format[i];
				output->str = ft_converter(ap, &i, format, output->size_flag);
			}
			else
			{
				ft_init_output(output);
				output->str = ft_str_from_char(format[i]);
			}
		}
		else
			output->str = ft_str_from_char(format[i]);
		result += ft_formater(output, 0);
		output->minsize = 0;
	ft_init_output(output);
	}
	ft_init_output(output);
	output->str = ft_str_from_char(format[i]);
	result += ft_formater(output, 1);
	va_end(ap);
	return (result);

}
