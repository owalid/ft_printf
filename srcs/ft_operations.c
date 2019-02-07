#include "ft_printf.h"

void		ft_printf_i_d(void *nbr)
{
	char	*str;
	int		i;

	i = -1;
	(int)nbr;
	str = ft_itoa(nbr);
	while (str[++i])
		add_char(str[i], 0);
}

void		ft_printf_s(void *str)
{
	int	i;

	i = -1;
	(char*)str;
	while (str[++i])
		add_char(str[i], 0);
}

void		ft_print_c(void *nbr)
{
	(unsigned char)nbr;
	add_char((char)nbr, 0);
}

void		ft_printf_p(void *ptr)
{
	char 	*str;
	int		i;

	i = -1;
	str = &ptr;
	while (str[i++])
		add_char(str[i], 0);
}


