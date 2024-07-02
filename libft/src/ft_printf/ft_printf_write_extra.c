/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 06:25:56 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 16:05:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_precision(t_format *f, int pad_size)
{
	if (f->precision < 0)
		return (1);
	if (!ft_printf_pad(f, pad_size, '0'))
		return (0);
	return (1);
}

int	prefix_hex(t_format *f, int mayus, size_t hex)
{
	char	*pre;

	if (f->spec != 'p' && !f->hashtag)
		return (1);
	if (f->spec != 'p' && hex == 0)
		return (1);
	if (mayus)
		pre = "0X";
	else
		pre = "0x";
	if (write(1, pre, 2) < 0)
		return (0);
	return (1);
}

int	prefix_signed(t_format *f, long num)
{
	char	*pre;

	if (num < 0)
		pre = "-";
	else if (f->space)
		pre = " ";
	else if (f->plus)
		pre = "+";
	else
		return (1);
	if (write(1, pre, 1) < 0)
		return (0);
	return (1);
}

int	ft_printf_pad(t_format *f, int pad_size, char pad_char)
{
	while (pad_size -- > 0)
	{
		if (write(1, &pad_char, 1) != 1)
			return (0);
		f->extra_len ++;
	}
	return (1);
}
