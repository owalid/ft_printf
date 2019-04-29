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
	else if (c == 'h')
	{
		if (output->size_flag->h)
		{
			output->size_flag->hh = 1;
			output->size_flag->h = 0;
		}
		else
			output->size_flag->h = 1;
	}
	else if (c == 'l')
	{
		if (output->size_flag->l)
		{
			output->size_flag->ll = 1;
			output->size_flag->l = 0;
		}
		else
			output->size_flag->l = 1;
	}
	else if (c == 'L')
		output->size_flag->bigl = 1;
}

int		ft_is_conv(char c)
{
	return ((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
				|| c == 'X' || c == 'c' || c == 's'
					|| c == 'p' ||  c == 'f' || c == '\0'));
}