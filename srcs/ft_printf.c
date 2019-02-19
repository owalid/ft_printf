#include "ft_opprintf.h"

int         ft_printf(const char *format, ...)
{
	va_list		ap;
	int     	o;
	size_t     	i;
	int			minsize;
	t_output	out[1];

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			o = -1;
			out->minsize = ft_isdigit(format[i + 1]) ? ft_printf_minsize(&format[i + 1]) : 0;
			i += get_size_nb(out->minsize);
			while (g_prtfop[++o].id)
			{
				if (g_prtfop[o].id == format[i + 1])
				{
					g_prtfop[o].ft_transform(ap, out);
					i += 2;
					break;
				}
			}
		}
		else
			add_char(format[i], 0);
		if (i == ft_strlen(format) - 1)
			add_char(format[i], 1);
	}
	va_end(ap);
	return (1);
}
