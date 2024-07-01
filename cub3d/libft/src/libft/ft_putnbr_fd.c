/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:58:48 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/24 16:41:12 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len ++;
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		ind;
	int		len;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	ind = 0;
	len = num_len(n);
	if (n < 0)
	{
		n *= -1;
		str[ind++] = '-';
	}
	str[len] = 0;
	while (ind < len)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len --;
	}
	ft_putstr_fd(str, fd);
}
