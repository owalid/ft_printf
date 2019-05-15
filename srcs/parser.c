#include "ft_printf.h"

void        pf_digit_prec(t_output *output, const char *format, int *i)
{
    int     j;
    char	*tmp;


    j = ++(*i);
    while (ft_isdigit(format[j]))
        j++;
    tmp = ft_strsub(format, *i, j);
    output->size_flag->precision = (size_t)ft_atoi(tmp);
    output->option->point = 1;
    if (format[j] != 'f' && (format[j] != 's')
    && format[j] != '%' && ft_is_conv(format[j])
    && output->minsize < output->size_flag->precision)
        output->minsize = output->size_flag->precision;
    if (format[j] == '%' || format[j + 1] == '%')
        output->minsize = 0;
    *i = --j;
    ft_strdel(&tmp);
}

void        pf_digit(t_output *output, const char *format, int *i)
{
    int     j;
    char    *tmp;

    j = *i;
    while (ft_isdigit(format[j]))
        j++;
    tmp = ft_strsub(format, *i, j);
    output->minsize = (size_t)ft_atoi(tmp);
    *i = j - 1;
    ft_strdel(&tmp);
}

void        pf_prec(t_output *output, const char *format, int *i)
{
    if (is_no_prec(format, *i))
    {
        output->size_flag->no_prec = 1;
        *i = (is_no_prec(format, *i) == 2) ? *i + 1 : *i;
    }
    else if (ft_isdigit(format[*i + 1]))
        pf_digit_prec(output, format, i);
}

void        pf_conv(t_output *output, const char *format, int *i)
{
    while (!ft_is_conv(format[*i]) && format[*i])
    {
        if (format[*i] == '.')
            pf_prec(output, format, i);
        else if (ft_isdigit(format[*i]) && format[*i] != '0')
            pf_digit(output, format, i);
        else if (ft_is_opt(format[*i]))
            ft_is_option(format[*i], output);
        else
            break;
        (*i)++;
    }
}