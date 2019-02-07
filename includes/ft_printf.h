#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/////////////////////
#include <stdio.h>
////////////////////

#include <stdarg.h>


typedef struct 		s_prtfop
{
	char 	id;
	void	(*ft_transform)(void *argv);
}					t_prtfop;

static typedef struct 	s_ptrbuff
{
	static char		str[1024];
	static int		size;
}						t_ptrbuff;

/*
**	ft_printf.c
*/
int			ft_printf(const char *format, ...);

/*
**	ft_operations.c
*/
void		ft_printnbr(void *nbr);

#endif
