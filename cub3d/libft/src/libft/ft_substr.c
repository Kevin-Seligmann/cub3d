/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:13:25 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/17 17:49:35 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	bcal(char const *s, size_t start, size_t len)
{
	size_t	slen;

	if (s == 0)
		return (0);
	start ++;
	slen = ft_strlen(s);
	if (start > slen)
		return (0);
	if (len > slen - start)
		return (slen - start + 1);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	first;
	size_t	ind;

	first = (size_t) start;
	len = bcal(s, first, len);
	str = (char *) malloc(len + 1);
	if (str == 0 || s == 0)
		return (0);
	ind = 0;
	while (ind < len && s[first + ind] != 0)
	{
		str[ind] = s[first + ind];
		ind ++;
	}
	str[ind] = 0;
	return (str);
}
