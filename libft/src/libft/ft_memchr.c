/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:56:17 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/05 17:24:11 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *input_string, int c, size_t limit)
{
	char	to_find;
	char	*str;
	size_t	ind;

	str = (char *) input_string;
	to_find = (unsigned char) c;
	if (limit <= 0)
		return (0);
	ind = 0;
	while (*str != to_find && ind < limit)
	{
		str ++;
		ind ++;
	}
	if (*str == to_find && ind != limit)
		return (str);
	return (0);
}
