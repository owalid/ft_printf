#include "ft_printf.h"

void		ft_printf_i_d(va_list ap)
{
	char	*str;
	int		i;
	int		nbr;

	i = -1;
	nbr = va_arg(ap, int);
	str = ft_itoa(nbr);
	while (str[++i])
		add_char(str[i], 0);
}

void		ft_printf_s(va_list ap)
{
	int		i;
	char	*str;

	str = va_arg(ap, char*);
	i = -1;
	while (str[++i])
		add_char(str[i], 0);
}

void		ft_printf_c(va_list ap)
{
	char 	nbr;

	nbr = va_arg(ap, int);
	add_char((char)nbr, 0);
}

void		ft_printf_p(va_list ap)
{
	char			*result;
	char			*add;
	char			*str;
	int				i;
	int				ptr;

	i = -1;
	ptr = va_arg(ap, unsigned int);
	str = ft_strnew(2);
	str[0] = '0';
	str[1] = 'x';
	add = ft_itoa_base(ptr, 16);
	result = ft_strjoin(str, add);
	while (result[++i])
		add_char(result[i], 0);
	ft_strdel(&str);
	ft_strdel(&add);
	ft_strdel(&result);
}

void		ft_printf_o(va_list ap)
{	
	char			*str;
	int				i;
	unsigned int	nbr;


	i = -1;
	nbr = va_arg(ap, unsigned int);	
	str = ft_itoa_base(nbr, 8);
	while (str[++i])
		add_char(str[i], 0);
}

void		ft_printf_u(va_list ap)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	i = -1;
	nbr = va_arg(ap, unsigned int);
	str = ft_itoa(nbr);
	while (str[i++])
		add_char(str[i], 0);
}

void		ft_printf_xX(va_list ap)
{
	char			*str;
	int				i;
	unsigned int	nbr;

	i = -1;
	nbr = va_arg(ap, unsigned int);
	str = ft_itoa_base(nbr, 16);
	while (str[i++])
		add_char(str[i], 0);
}
