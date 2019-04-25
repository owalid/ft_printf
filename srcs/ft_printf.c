#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format)
{
	int	o;
	
	o = -1;
	while (g_prtfop[++o].id)
	{
		if (g_prtfop[o].id == format[*i])
		{
			return (g_prtfop[o].ft_transform(ap));
		}
	}
	return (NULL);
}

int         ft_printf(const char *format, ...)
{
	t_output 	output[1];
	t_option    option[1];
    t_sizeflag  flag[1];
	va_list		ap;
	int 		i;
	char		*tmp;

	va_start(ap, format);
	i = -1;
	ft_init_option(option);
	ft_init_sizeflag(flag);
	ft_init_output(output);
	output->option = option;
    output->size_flag = flag;
	while (format[++i])
	{
		ft_init_option(output->option);
		ft_init_sizeflag(output->size_flag);
		if (format[i] == '%')
		{
			i++;
			while (!ft_is_conv(format[i]))
			{
				if (format[i] == '.')
				{
					tmp = ft_str_from_char(format[i]);
					output->precision = ft_atoi(tmp);
					ft_strdel(&tmp);
				}
				else
					ft_is_option(format[i], output);
				i++;
			}
			output->conv_type = format[i];
			output->str = ft_converter(ap, &i, format);
		}
		else
			output->str = ft_str_from_char(format[i]);
		ft_formater(output, 0);
		ft_clean_output(output);
	}
	ft_init_option(output->option);
	ft_init_sizeflag(output->size_flag);
	output->str = ft_str_from_char(format[i]);
	ft_formater(output, 1);
	va_end(ap);
	return (0);

}
