#ifndef FT_OPPRINTF_H
# define FT_OPPRINTF_H

# include "ft_printf.h"
# include "libft.h"

static t_prtfop g_prtfop[] =
{
	{'d', &ft_printf_i_d},
	{'i', &ft_printf_i_d},
	{'o', &ft_printf_o},
	{'u', &ft_printf_u},
	{'U', &ft_printf_U},
	{'x', &ft_printf_x},
	{'X', &ft_printf_X},
	{'c', &ft_printf_c},
	{'s', &ft_printf_s},
	{'p', &ft_printf_p},
	{'s', &ft_printf_s},
	{'f', &ft_printf_f},
	{'\0', &ft_printf_i_d}
};

# endif
