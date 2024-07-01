/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:39:32 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/22 11:37:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ITOA_BASE_BUFFER 32

char	*ft_itoa_base(size_t n, char *base)
{
	char	p_c[ITOA_BASE_BUFFER + 1];
	int		base_len;
	int		i;

	if (!base || !(*base))
		return (0);
	base_len = ft_strlen(base);
	i = ITOA_BASE_BUFFER - 1;
	while (n > 0 || i == ITOA_BASE_BUFFER - 1)
	{
		p_c[i] = base[n % base_len];
		n /= base_len;
		i --;
	}
	p_c[ITOA_BASE_BUFFER] = 0;
	return (ft_strdup(p_c + i + 1));
}
