/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specified.c                        :+:      :+:    :+:         */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:19:58 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 16:05:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(t_format *f, unsigned char c)
{
	if (f->minus)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		if (!ft_printf_pad(f, f->width - 1, f->pad_char))
			return (-1);
	}
	else
	{
		if (!ft_printf_pad(f, f->width - 1, f->pad_char))
			return (-1);
		if (write(1, &c, 1) < 0)
			return (-1);
	}
	return (f->extra_len + 1);
}

int	ft_printf_s(t_format *f, char *s)
{
	if (!s)
		s = "(null)";
	f->str_len = ft_strlen(s);
	if (f->precision > -1 && f->str_len > f->precision)
		f->str_len = f->precision;
	if (f->minus)
	{
		if (write(1, s, f->str_len) < 0)
			return (-1);
		if (!ft_printf_pad(f, f->width - f->str_len, f->pad_char))
			return (-1);
	}
	else
	{
		if (!ft_printf_pad(f, f->width - f->str_len, f->pad_char))
			return (-1);
		if (write(1, s, f->str_len) < 0)
			return (-1);
	}
	return (f->str_len + f->extra_len);
}

static int	safe_return(char *str)
{
	free(str);
	return (-1);
}

int	ft_printf_dec(t_format *f, long dec)
{
	char	*str;

	if (f->precision == 0 && dec == 0)
		str = ft_strdup("");
	else if (dec > 0)
		str = ft_itoa_base(dec, "0123456789");
	else
		str = ft_itoa_base(-dec, "0123456789");
	if (!str)
		return (-1);
	f->str_len = ft_strlen(str);
	if (ft_strchr("id", f->spec) && (dec < 0 || f->space || f->plus))
		f->extra_len ++;
	if (f->minus)
	{
		if (!ft_printf_left_dec(f, str, dec))
			return (safe_return(str));
	}
	else
	{
		if (!ft_printf_right_dec(f, str, dec))
			return (safe_return(str));
	}
	free(str);
	return (f->str_len + f->extra_len);
}

int	ft_printf_x(t_format *f, size_t hex, char mayus)
{
	char	*str;

	if (f->precision == 0 && hex == 0)
		str = ft_strdup("");
	else if (mayus)
		str = ft_itoa_base(hex, "0123456789ABCDEF");
	else
		str = ft_itoa_base(hex, "0123456789abcdef");
	if (!str)
		return (-1);
	if ((f->hashtag && hex > 0) || f->spec == 'p')
		f->extra_len += 2;
	f->str_len = ft_strlen(str);
	if (f->minus)
	{
		if (!ft_printf_left_hex(f, str, hex, mayus))
			return (safe_return(str));
	}
	else
	{
		if (!ft_printf_right_hex(f, str, hex, mayus))
			return (safe_return(str));
	}
	free(str);
	return (f->str_len + f->extra_len);
}
