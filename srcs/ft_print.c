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
	if (output->conv_type == 'd' || output->conv_type == 'f' ||  output->conv_type == 'i')
		return (ft_formater_df(output, opt));
	else if (output->conv_type == 's')
		return (ft_formater_sc(output, opt));
	else if (output->conv_type == 'x' || output->conv_type == 'X')
		return (ft_formater_xX(output, opt));
	else if (output->conv_type == 'p')
		return (ft_formater_p(output, opt));
	else if (output->conv_type == 'u' || output->conv_type == 'U')
		return (ft_formater_u(output, opt));
	else if (output->conv_type == 'o')
		return (ft_formater_o(output, opt));
	else
		return (ft_formater_df(output, opt));
	
}
