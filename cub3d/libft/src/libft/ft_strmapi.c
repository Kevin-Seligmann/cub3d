/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:36:06 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 19:56:50 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	ind;
	char	*str;

	if (!f)
		return (0);
	ind = 0;
	len = ft_strlen(s);
	str = (char *) malloc(len + 1);
	if (!str)
		return (0);
	while (ind < len)
	{
		str[ind] = f((unsigned int) ind, s[ind]);
		ind ++;
	}
	str[len] = 0;
	return (str);
}
