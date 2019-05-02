#include "ft_printf.h"

void		add_char(char c, int opt)
{
	static char		str[1024];
	static int		size;

	if (ft_strlen(str) == 0)
		size = 0;
	if (size == 1024 || opt)
	{
		write(1, str, size);
		str[0] = '\0';
		size = 0;
	}
	else
	{
		str[size] = c;
		size++;
	}
}

int		ft_formater(t_output *output, int opt)
{
	if (output->conv_type == 'd')
		return (ft_formater_df(output, opt));
	else if (output->conv_type == 's')
		return (ft_formater_sc(output, opt));
	else
		return (ft_formater_df(output, opt));
}
