#ifndef FT_OPPRINTF_H
# define FT_OPPRINTF_H

# include "ft_printf.h"

static t_prtfop g_prtfop[] =
{
	{'d', &ft_printnbr},
	{'s', &ft_printstr},
	{'\0', &ft_printnbr},
};

# endif
