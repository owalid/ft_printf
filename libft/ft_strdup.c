/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 01:05:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/14 12:31:22 by oel-ayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = ft_strnew(ft_strlen(src))))
		return (NULL);
	while (src[++i] != '\0')
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
