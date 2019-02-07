#include "ft_printf.h"

void			ft_printnbr(void *nbr)
{
	char	*str;
	int		i;

	i = -1;
	(int)nbr;
	str = ft_itoa(nbr);
	while (str[++i])
		add_char(str[i], 0);
}
