/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:20:00 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/12 01:50:39 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, size_t start, size_t len)
{
	char		*result;

	result = ft_strnew(len);
	if (!result || !s)
		return (NULL);
	result = ft_strncpy(result, s + start, len);
	return (result);
}
