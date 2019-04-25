#include "ft_opprintf.h"

char		*ft_converter(va_list ap, int *i, const char *format)
{
	int	o;
	
	o = -1;
	while (g_prtfop[++o].id)
	{
		if (g_prtfop[o].id == format[*i - 1])
		{
			return (g_prtfop[o].ft_transform(ap));
		}
	}
	return (NULL);
}

int         ft_printf(const char *format, ...)
{
	t_output 	output[1];
	va_list		ap;
	int 		i;
	int			t;

	va_start(ap, format);
	t = -1;
	i = -1;
	ft_init_output(output);
	while (format[++i])
	{
		printf("%d\n", i);
		if (format[i] == '%')
		{
			while (!ft_is_conv(format[i++]))
			{
				if (format[i] == '.')
					output->precision = ft_atoi(&format[i]);
				else
					ft_is_option(format[i], output);
			}
			output->conv_type = format[i];
			output->str = ft_converter(ap, &i, format);
		}
		if ((size_t)i == ft_strlen(format) - 1)
			ft_formater(output, 1);
		else
			ft_formater(output, 0);
		ft_clean_output(output);
	}
	va_end(ap);
	return (0);
}
