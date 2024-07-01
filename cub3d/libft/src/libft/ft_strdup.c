/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:57:27 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/13 20:13:05 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	ind;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = (char *) malloc(len + 1);
	if (!cpy)
		return (0);
	ind = 0;
	while (ind < len)
	{
		cpy[ind] = s1[ind];
		ind ++;
	}
	cpy[ind] = 0;
	return (cpy);
}
