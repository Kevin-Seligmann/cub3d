/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:28:11 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 21:55:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	l;
	char	*ptr;
	size_t	len;
	size_t	count;

	ptr = (char *) s;
	len = ft_strlen(s);
	l = (char) c;
	count = 0;
	while (count <= len)
	{
		if (ptr[len - count] == l)
			return (&(ptr[len - count]));
		count ++;
	}
	return (0);
}
