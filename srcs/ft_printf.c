#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format
									, t_output *out)
{
	int		o;

	o = -1;
	while (g_prtfop[++o].id)
	{
		if (g_prtfop[o].id == format[*i])
		{
			out->str = g_prtfop[o].ft_transform(ap, out->size_flag);
			return (out->str);
		}
	}
	out->str = ft_str_from_char(format[*i]);
	return (out->str);
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
			while (!ft_is_conv(format[i]) && format[i])
			{
				if (format[i] == '.')
				{
					if (is_no_prec(format, i))
					{
						output->size_flag->no_prec = 1;
						i = (is_no_prec(format, i) == 2) ? i + 1 : i;
					}
					else if (ft_isdigit(format[i + 1]))
					{
						j = ++i;
						while (ft_isdigit(format[j]))
							j++;
						tmp = ft_strsub(format, i, j);
						output->size_flag->precision = (size_t)ft_atoi(tmp);
						output->option->point = 1;
						if (format[j] != 'f' && (format[j] != 's')
						&& format[j] != '%' && ft_is_conv(format[j])
						&& output->minsize < output->size_flag->precision)
							output->minsize = output->size_flag->precision;
						if (format[j] == '%' || format[j + 1] == '%')
							output->minsize = 0;
						i = --j;
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
			else if (ft_is_conv(format[i]) && format[i] != '%')
			{
				output->conv_type = format[i];
				output->str = ft_converter(ap, &i, format, output);
			}
			else
			{
				output->option->space = 0;
				output->option->plus = 0;
				output->size_flag->precision = 0;
				output->conv_type = 'y';
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
	// ft_strdel(&(output->str));
	va_end(ap);
	// free(&ap);
	return (result);
}
