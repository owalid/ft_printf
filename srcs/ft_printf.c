#include "ft_printf.h"

int         ft_printf(const char *format, ...)
{
	va_list		ap;
	int     	o;
	int     	i;

	i = -1;
	va_start(ap);

	while (format[++i])
	{
		if (format[i] == '%')
		{
			o = 0;
			while (g_ptrlop[o].id)
			{
				if (g_ptrlop[o].id == format[i + 1])
					g_ptrlop[o].ft_transorm(va_arg(ap));
				o++;
			}
		}
	}
	va_end(ap);
}

