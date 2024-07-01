/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:01:10 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 22:02:27 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (dstsize > 0)
	{
		while (count + 1 < dstsize && src[count] != 0)
		{
			dst[count] = src[count];
			count ++;
		}
		dst[count] = 0;
	}
	return (ft_strlen(src));
}
