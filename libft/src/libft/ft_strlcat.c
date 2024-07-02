/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:05:02 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 19:55:52 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	count;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	count = 0;
	while (count + dstlen + 1 < dstsize && src[count] != 0)
	{
		dst[dstlen + count] = src[count];
		count ++;
	}
	if (dstsize > 0 && dstsize >= dstlen)
		dst[dstlen + count] = 0;
	if (dstsize < dstlen)
		return (dstsize + srclen);
	return (dstlen + srclen);
}
