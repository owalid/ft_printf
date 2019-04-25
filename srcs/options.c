#include "ft_printf.h"

void	ft_is_option(char c, t_output *output)
{
	if (c == '#')
		output->option->hash = 1;
	else if (c == '0') 
		output->option->zero = 1;
	else if (c == '-')
		output->option->min = 1;
	else if (c == '+')
		output->option->plus = 1;
	else if (c == ' ')
		output->option->space = 1;
	else if (ft_isdigit(c))
		output->minsize = (size_t)ft_atoi(&c);
}

int		ft_is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '\0')
		return (1);
	return (0);
}