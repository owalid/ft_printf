#include "ft_printf.h"

void        ft_prepare_for_y(t_output *output, const char *format, int i)
{
    output->option->space = 0;
    output->option->plus = 0;
    output->size_flag->precision = 0;
    output->conv_type = 'y';
    output->str = ft_str_from_char(format[i]);
}

void        ft_prepare(t_output *output, const char *format, int i, va_list ap)
{
    output->conv_type = format[i];
    output->str = ft_converter(ap, &i, format, output);
}