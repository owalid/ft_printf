#include "ft_printf.h"

void	ft_is_option(char c, t_output *output)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
	{
		if (ft_strchr(output->options, c) == NULL)
			output->options = ft_strjoin(output->options, c);//todo protect
	}
	else if (ft_isdigit(c))
		output->minsize = (size_t)ft_atoi(c);
}

int		ft_is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'c' || c == 's' || c == 'p' || c == '\0')
		return (1);
	return (0);
}