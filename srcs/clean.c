#include "ft_printf.h"

void        ft_init_option(t_option *option)
{
    option->hash = 0;
    option->space = 0;
    option->zero = 0;
    option->min = 0;
    option->plus = 0;
}

void        ft_init_sizeflag(t_sizeflag *flag)
{
    flag->h = 0;
    flag->hh = 0;
    flag->l = 0;
    flag->ll = 0;
}

void        ft_init_output(t_output *out)
{
    t_option    option[1];
    t_sizeflag  flag[1];

    out->minsize = 0;
    out->precision = 0;
    out->conv_type = 0;
    ft_init_option(option);
    out->option = option;
    ft_init_sizeflag(flag);
    out->size_flag = flag;
}

void        ft_clean_output(t_output *out)
{
    ft_init_output(out);
    ft_strdel(&out->str);
}