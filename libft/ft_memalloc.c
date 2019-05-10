/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owalid <owalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:07:54 by oel-ayad          #+#    #+#             */
/*   Updated: 2019/05/10 23:41:47 by owalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*result;

	if (size < 0)
		size = 1;
	if ((result = malloc(size)) == NULL)
		return (NULL);
	result = ft_memset(result, 0, size);
	return (result);
}
