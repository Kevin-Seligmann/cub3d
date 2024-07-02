/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:24:05 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 15:46:13 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	char	*str;

	str = (char *) set;
	while (*str != 0)
	{
		if (c == *str)
			return (1);
		str ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_substr(s1, start, 0));
	while (char_in_set(s1[start], set))
		start ++;
	while (char_in_set(s1[end], set))
		end --;
	if (end + 1 > start)
		return (ft_substr(s1, start, end - start + 1));
	return (ft_substr(s1, start, 0));
}
