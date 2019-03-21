#include "ft_printf.h"

char	*conf_output(t_output *out, va_list ap)
{
	char	*sortie;
	char	*mods;

	mods = ft_strnew(&out->minsize);
	if (&out->options->plus)
		ap > 0 ? mods[0] = '+' : 0;
	
}