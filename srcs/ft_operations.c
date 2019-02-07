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
	str = ft_strdup(&ptr);
	while (str[i++])
		add_char(str[i], 0);
	ft_strdel(&str);
}

void		ft_printf_o(void *nbr)
{
	char	*str;
	int		i;

	i = -1;
	(unsigned int)nbr;
	str = ft_itoa_base(nbr, 8);
	while (str[i++])
		add_char(str[i], 0);
}

void		ft_printf_u(void *nbr)
{
	char	*str;
	int		i;

	i = -1;
	(unsigned int)nbr;
	str = ft_itoa(nbr);
	while (str[i++])
		add_char(str[i], 0);
}

void		ft_printf_xX(void *nbr)
{
	char	*str;
	int		i;

	i = -1;
	(unsigned int)nbr;
	str = ft_itoa_base(nbr, 16);
	while (str[i++])
		add_char(str[i], 0);
}

void		ft_printf_percent(void *per)
{
	add_char('%', 0);
}
