#include "ft_printf.h"

void	ft_is_option(char c, t_output *output)
{
	if (c == '#')
		output->option->hash = 1;
	else if (c == '0')
	{
		output->option->zero = 1;
	}
	else if (c == '-')
	{
		output->option->min = 1;
	}
	else if (c == '+')
		output->option->plus = 1;
	else if (c == ' ')
	{
		output->option->space = 1;
	}
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
	else if (c == 'j')
		output->size_flag->j = 1;
	else if (c == 'z')
		output->size_flag->z = 1;
	else
		output->str = ft_str_from_char(c);
}

int		ft_is_conv(char c)
{
	return ((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'U' || c == 'x'
				|| c == 'X' || c == 'c' || c == 's'
					|| c == 'p' ||  c == 'f' || c == '\0' || c == '%'));
}

int		ft_is_opt(char c)
{
	return (c == '#' || c == '0' || c == ' '
				|| c == '-' || c == '+' || c == 'h'
				|| c == 'l' || c == 'j' || c == 'L' || c == 'z');
}