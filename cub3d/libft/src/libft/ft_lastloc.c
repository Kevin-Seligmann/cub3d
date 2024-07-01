/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:08:31 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/23 17:35:22 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lastloc(size_t count, size_t size)
{
	char	*p;

	p = malloc(count * size * sizeof(*p));
	if (!p)
		return (0);
	p[count * size - 1] = 0;
	return ((void *) p);
}
