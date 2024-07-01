/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:10:59 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/16 22:07:23 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ind;

	ind = 0;
	while (ind < n)
	{
		if (s1[ind] == 0 || s2[ind] == 0 || s1[ind] != s2[ind])
			return ((unsigned char) s1[ind] - (unsigned char) s2[ind]);
		ind ++;
	}
	return (0);
}
