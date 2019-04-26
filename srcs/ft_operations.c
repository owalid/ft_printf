#include "ft_printf.h"

char		*ft_printf_i_d(va_list ap)
{
	char	*result;

	result = ft_itoa(va_arg(ap, int));
	return (result);
}

char		*ft_printf_s(va_list ap)
{
	return (va_arg(ap, char*));
}

char		*ft_printf_c(va_list ap)
{
	char	*result;
	
	result = ft_strnew(2);
	result[0] = va_arg(ap, int);
	return (result);
}

char		*ft_printf_p(va_list ap)
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
	return(result);
}

char		*ft_printf_o(va_list ap)
{	
	int				i;
	unsigned int	nbr;


	i = -1;
	nbr = va_arg(ap, unsigned int);	
	return(ft_itoa_base(nbr, 8));
}

char		*ft_printf_u(va_list ap)
{
	int				i;
	unsigned int	nbr;

	i = -1;
	nbr = va_arg(ap, unsigned int);
	return (ft_itoa(nbr));
}

char		*ft_printf_xX(va_list ap)
{
	unsigned int	nbr;

	nbr = va_arg(ap, unsigned int);
	return (ft_itoa_base(nbr, 16));
}
