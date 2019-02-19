
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

void	ft_output(t_output *output)
{
	int		diff;
	int		i;

	diff = ft_strlen(output->str) - output->minsize;
	if (diff > 0)
	{
		add_char(output->option, 0);
		diff--;
	}
	i = -1;
	while (output->str[++i])
		add_char(output->str[i], 0);
}
