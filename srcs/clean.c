#include "ft_printf.h"

void        ft_init_option(t_option *option)
{
    option->hash = 0;
    option->space = 0;
    option->zero = 0;
    option->min = 0;
    option->plus = 0;
    option->point = 0;
}

void        ft_init_sizeflag(t_sizeflag *flag)
{
    flag->h = 0;
    flag->hh = 0;
    flag->l = 0;
    flag->ll = 0;
    flag->precision = 0;
    flag->no_prec = 0;
}

void        ft_init_output(t_output *out)
{
    ft_init_option(out->option);
    ft_init_sizeflag(out->size_flag);
    out->is_null = 0;
    out->minsize = 0;
    out->conv_type = 0;
}

void        ft_clean_output(t_output *out)
{
    out->conv_type = 0;
}