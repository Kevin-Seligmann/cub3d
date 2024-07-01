/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:28:39 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/13 19:22:04 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hind;
	size_t	nind;

	hind = 0;
	if (*needle == 0)
		return ((char *) &(haystack[hind]));
	while (haystack[hind] != 0 && hind < len)
	{
		nind = 0;
		while (needle[nind] == haystack[hind + nind] && hind + nind < len)
		{
			if (needle[nind + 1] == 0)
				return ((char *) &(haystack[hind]));
			nind ++;
		}
		hind ++;
	}
	return (0);
}
