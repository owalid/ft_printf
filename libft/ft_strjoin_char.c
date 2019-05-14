/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 07:44:29 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/14 07:46:13 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_strjoin_char(char c, char *s1, int opt)
{
    char        *tmp;
    char        *result;

    tmp = ft_str_from_char(c);
    result = (opt == 1) ? ft_strjoin_free(tmp, s1) : ft_strjoin_free(s1, tmp);
    return (result);
}