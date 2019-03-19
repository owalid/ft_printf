#include "ft_printf.h"

int			ft_printf_minsize(char *str)
{
	int		minsize;

	minsize = ft_atoi(str);
	return (minsize);
}

void		ft_printf_i_d(va_list ap, t_output *out)
{
	int		i;
	int		nbr;

	i = -1;
	nbr = va_arg(ap, int);
	out->str = ft_itoa(nbr);
	ft_print(out->str);
}

void		ft_printf_s(va_list ap, t_output *out)
{
	int		i;
	char	*str;

	out->str = va_arg(ap, char*);
	i = -1;
	ft_print(out->str);
}

void		ft_printf_c(va_list ap, t_output *out)
{
	char 	cara;

	out->str = va_arg(ap, int);
	ft_print(out->str);
}

void		ft_printf_p(va_list ap, t_output *out)
{
	char			*result;
	char			*add;
	char			*str;
	int				i;
	int				ptr;

	i = -1;
	ptr = va_arg(ap, unsigned int);
	out->str = ft_strnew(2);
	out->str[0] = '0';
	out->str[1] = 'x';
	add = ft_itoa_base(ptr, 16);
	result = ft_strjoin(out->str, add);
	ft_print(out->str)
	ft_strdel(&out->str);
	ft_strdel(&add);
	ft_strdel(&result);
}

void		ft_printf_o(va_list ap, t_output *out)
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
