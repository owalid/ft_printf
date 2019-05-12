#include "ft_printf.h"

char        *ft_add_blank(t_output *output, char *result, int opt)
{
    char	*tmp;
    size_t     i;

    i = 0;
    tmp = ft_strnew(output->minsize - ft_strlen(result));
    while (i < output->minsize - ft_strlen(result))
        tmp[(i)++] = ' ';
    if (i != 0)
            result = (opt == 1) ? ft_strjoin(result, tmp) : ft_strjoin(tmp, result);
    ft_strdel(&tmp);
    return (result);
}

void        send_char(char *result, int opt, size_t *i)
{
    if (opt == 1 && !*result)
		add_char(0, opt);
	*i = -1;
	while (result[++(*i)])
		add_char(result[*i], opt);
    ft_strdel(&result);
}

void        ft_is_null(t_output *output)
{
    output->is_null = 1;
    if (!output->option->plus && !output->option->min && !output->option->point && !output->size_flag->no_prec)
        output->str = ft_strdup("(null)");
    else if (output->conv_type != 'f' && output->conv_type != 'x')
        ft_strclr(output->str);
}

int        is_no_prec(const char *format, int i)
{
    if ((!ft_isdigit(format[i + 1])
							&& (format[i + 1] == 'f' || format[i + 1] == 'd'
                                || format[i + 1] == 'i' || format[i + 1] == 'u'
                                || format[i + 1] == 'x' || format[i + 1] == 'X'
                                || format[i + 1]  == 'o' || format[i + 1] == 'p'
                                || format[i + 1] == 's')))
        return (1);
    else if ((format[i + 1] == '0'
                            && (format[i + 2] == 'f' || format[i + 2] == 'd'
                                || format[i + 2] == 'i' || format[i + 2] == 'u'
                                || format[i + 2] == 'x' || format[i + 2] == 'X'
                                || format[i + 2]  == 'o' || format[i + 2] == 'p'
                                || format[i + 2] == 's')))
        return (2);
    return(0);
}

int         one_option(t_output *out)
{
    return ((out->option->min || out->option->space
                || out->option->plus || out->option->hash
                || out->option->point || out->option->zero));
}