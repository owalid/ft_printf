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
    if (opt == 1 && !result[0])
		add_char(0, opt);
	*i = -1;
	while (result[++(*i)])
		add_char(result[*i], opt);
	ft_strdel(&result);
}

int        is_no_prec(const char *format, int i)
{
    if ((!ft_isdigit(format[i + 1])
							&& (format[i + 1] == 'f' || format[i + 1] == 'd'
								|| format[i + 1] == 'x' || format[i + 1] == 'X'
								|| format[i + 1]  == 'o')))
        return (1);
    else if ((format[i + 1] == '0' && 
								(format[i + 2] == 'f' || format[i + 2] == 'd'
                                || format[i + 2] == 'x' || format[i + 2] == 'X'
                                || format[i + 2]  == 'o')))
        return (2);
    return(0);
}