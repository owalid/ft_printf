#include "ft_printf.h"

void	ft_is_option(char c, t_output *output)
{
	char	*str;

	str = ft_str_from_char(c);
	if (str[0] == '#')
		output->option->hash = 1;
	else if (str[0] == '0') 
		output->option->zero = 1;
	else if (str[0] == '-')
		output->option->min = 1;
	else if (str[0] == '+')
		output->option->plus = 1;
	else if (str[0] == ' ')
		output->option->space = 1;
	else if (ft_isdigit(str[0]))
		output->minsize = (size_t)ft_atoi(str);
	ft_strdel(&str);
}

int		ft_is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '\0')
		return (1);
	return (0);
}