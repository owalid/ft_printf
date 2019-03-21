#include "ft_opprintf.h"

int         ft_printf(const char *format, ...)
{
	t_output 	*output;
	int 		i;
	int			t;

	t = -1;
	i = -1;
	while (format[i++])
	{
		if (format[i] == '%')
		{
			while (ft_is_option(format[i++], &output->options));
			output->minsize = ft_print_minsize(&format[i]);
			output->precision = format[i + output->minsize] == '.' ? ft_atoi(format[i + output->minsize] + 1) : 0;
			while (!(ft_is_conv(format[i++])));
			while (g_prtfop[t++].id)
			{
				g_prtfop[t].id == format[i] ? 
			}
		}
	}
}
