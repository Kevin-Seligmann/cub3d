/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:33:50 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 16:05:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_left_dec(t_format *f, char *str, long dec)
{
	if (!prefix_signed(f, dec))
		return (0);
	if (!ft_printf_precision(f, f->precision - f->str_len))
		return (0);
	if (write(1, str, f->str_len) < 0)
		return (0);
	if (!ft_printf_pad(f, f->width - f->str_len - f->extra_len, f->pad_char))
		return (0);
	return (1);
}

int	ft_printf_left_hex(t_format *f, char *str, size_t hex, char mayus)
{
	if (!prefix_hex(f, mayus, hex))
		return (0);
	if (!ft_printf_precision(f, f->precision - f->str_len))
		return (0);
	if (write(1, str, f->str_len) < 0)
		return (0);
	if (!ft_printf_pad(f, f->width - f->str_len - f->extra_len, f->pad_char))
		return (0);
	return (1);
}

int	ft_printf_right_dec(t_format *f, char *str, long dec)
{
	int	pad_size;

	pad_size = f->width - f->str_len - f->extra_len;
	if (f->pad_char == '0')
	{
		if (\
		!prefix_signed(f, dec) || \
		!ft_printf_precision(f, f->precision - f->str_len) || \
		!ft_printf_pad(f, pad_size, f->pad_char) || \
		write(1, str, f->str_len) < 0)
			return (0);
	}
	else
	{
		if (f->precision > f->str_len)
			pad_size -= (f->precision - f->str_len);
		if (\
		!ft_printf_pad(f, pad_size, f->pad_char) || \
		!prefix_signed(f, dec) || \
		!ft_printf_precision(f, f->precision - f->str_len) || \
		write(1, str, f->str_len) < 0)
			return (0);
	}
	return (1);
}

int	ft_printf_right_hex(t_format *f, char *str, size_t hex, char mayus)
{
	int	pad_size;

	pad_size = f->width - f->str_len - f->extra_len;
	if (f->pad_char == '0')
	{
		if (\
		!prefix_hex(f, mayus, hex) || \
		!ft_printf_precision(f, f->precision - f->str_len) || \
		!ft_printf_pad(f, pad_size, f->pad_char) || \
		write(1, str, f->str_len) < 0)
			return (0);
	}
	else
	{
		if (f->precision > f->str_len)
			pad_size -= (f->precision - f->str_len);
		if (\
		!ft_printf_pad(f, pad_size, f->pad_char) || \
		!prefix_hex(f, mayus, hex) || \
		!ft_printf_precision(f, f->precision - f->str_len) || \
		write(1, str, f->str_len) < 0)
			return (0);
	}
	return (1);
}
