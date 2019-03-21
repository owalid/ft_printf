#include "ft_printf.h"

int		ft_is_option(char c, t_options *options)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
	{
		if (options->diese != 1)
			options->diese = c == '#' ? 1 : 0;
		if (options->zero != 1)
			options->zero = c == '0' ? 1 : 0;
		if (options->moins != 1)
			options->moins = c == '-' ? 1 : 0;
		if (options->plus != 1)
			options->plus = c == '+' ? 1 : 0;
		if (options->espace != 1)
			options->espace = c == ' ' ? 1 : 0;
		return (1);
	}
	return (0);
}

int		ft_is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || 
		c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '\0')
		return (1);
	return (0);
}