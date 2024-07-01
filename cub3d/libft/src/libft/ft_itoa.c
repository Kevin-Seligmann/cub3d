/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:23:31 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/23 17:30:14 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ITOA_BUFFER 11
#define MIN_INT -2147483648
#define MIN_INT_S "-2147483648"

char	*ft_itoa(int n)
{
	char	result[ITOA_BUFFER + 1];
	int		i;
	int		is_gt_zero;

	if (n == MIN_INT)
		return (ft_strdup(MIN_INT_S));
	is_gt_zero = 1;
	if (n < 0)
	{
		n *= -1;
		is_gt_zero = 0;
	}
	i = ITOA_BUFFER - 1;
	while (n > 0 || i == ITOA_BUFFER - 1)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i --;
	}
	if (!is_gt_zero)
		result[i --] = '-';
	result[ITOA_BUFFER] = 0;
	return (ft_strdup(result + i + 1));
}
