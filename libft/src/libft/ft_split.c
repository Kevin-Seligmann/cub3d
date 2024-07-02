/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:43:00 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 17:24:31 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_space(char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			len ++;
		s ++;
	}
	return (len + 1);
}

static char	**freeall(char ***strs, size_t ind)
{
	size_t	indf;

	indf = 0;
	while (indf < ind)
	{
		free((*strs)[indf]);
		indf ++;
	}
	free(*strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*str;
	size_t	count;
	size_t	ind;

	strs = (char **) malloc(total_space((char *) s, c) * sizeof(char *));
	if (!strs || !s)
		return (0);
	str = (char *) s;
	ind = 0;
	while (*str)
	{
		count = 1;
		if (*str != c)
		{
			while (str[count] && str[count] != c)
				count ++;
			strs[ind] = ft_substr(str, 0, count);
			if (!strs[ind ++])
				return (freeall(&strs, ind));
		}
		str += count;
	}
	strs[ind] = 0;
	return (strs);
}
