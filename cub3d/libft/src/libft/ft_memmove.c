/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:38:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/14 06:23:21 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src && len > 0)
		return (0);
	i = 0;
	if (dst > src)
	{
		while (i < len)
		{
			((char *) dst)[len - i - 1] = ((char *) src)[len - i - 1];
			i ++;
		}
	}
	else
	{
		while (i < len)
		{
			((char *) dst)[i] = ((char *) src)[i];
			i ++;
		}
	}
	return (dst);
}
