#include "ft_printf.h"

void        ft_init_option(t_option *option)
{
    option->hash = 0;
    option->space = 0;
    option->zero = 0;
    option->min = 0;
    option->plus = 0;
}

void        ft_clean_output(t_output *out)
{
    ft_init_option(out->option);
    out->minsize = 0;
    out->precision = 0;
    out->conv_type = 0;
    ft_strdel(&out->str);
    ft_strdel(&out->taille);
}