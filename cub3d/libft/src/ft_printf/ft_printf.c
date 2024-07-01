/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:28:04 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 16:05:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	clean_format(t_format *format, int reset)
{
	if (reset || !format->spec)
	{
		format->spec = 0;
		format->plus = 0;
		format->minus = 0;
		format->space = 0;
		format->hashtag = 0;
		format->mayus = 0;
		format->pad_char = ' ';
		format->width = 0;
		format->precision = -1;
		format->str_len = 0;
		format->extra_len = 0;
	}
	else
	{
		if (format->plus || ft_strchr("uxX", format->spec))
			format->space = 0;
		if (format->minus || format->precision > -1)
			format->pad_char = ' ';
		if (format->spec == 'X')
			format->mayus = 1;
		if (format->spec == 'p')
			format->hashtag = 1;
	}
}

static size_t	get_w_or_p(char const *str, int *p_value, size_t ind)
{
	int	count;
	int	value;

	count = 0;
	value = 0;
	if (str[ind] == '.')
		count ++;
	while (str[ind + count] >= '0' && str[ind + count] <= '9')
	{
		value = value * 10 + str[ind + count] - '0';
		count ++;
	}
	*p_value = value;
	if (count == 0)
		return (0);
	return (count - 1);
}

static void	set_format(char const *str, t_format *format, size_t *ind)
{
	(*ind)++;
	while (str[*ind] && ft_strchr("-+0 #.123456789", str[*ind]))
	{
		if (str[*ind] == '-')
			format->minus = 1;
		else if (str[*ind] == '+')
			format->plus = 1;
		else if (str[*ind] == '0')
			format->pad_char = '0';
		else if (str[*ind] == ' ')
			format->space = 1;
		else if (str[*ind] == '#')
			format->hashtag = 1;
		else if (str[*ind] == '.')
			*ind += get_w_or_p(str, &(format->precision), *ind);
		else if (str[*ind] >= '1' && str[*ind] <= '9')
			*ind += get_w_or_p(str, &(format->width), *ind);
		(*ind)++;
	}
	format->spec = str[*ind];
	if (format->spec)
		(*ind)++;
	clean_format(format, 0);
}

static size_t	go_to_spec_function(va_list ap, t_format *format)
{
	if (format->spec == 0)
		return (0);
	else if (format->spec == 'c')
		return (ft_printf_c(format, (unsigned char) va_arg(ap, int)));
	else if (format->spec == 's')
		return (ft_printf_s(format, (char *) va_arg(ap, const char *)));
	else if (format->spec == 'd')
		return (ft_printf_dec(format, va_arg(ap, int)));
	else if (format->spec == 'i')
		return (ft_printf_dec(format, va_arg(ap, int)));
	else if (format->spec == 'u')
		return (ft_printf_dec(format, va_arg(ap, unsigned int)));
	else if (format->spec == 'x')
		return (ft_printf_x(format, va_arg(ap, unsigned int), 0));
	else if (format->spec == 'X')
		return (ft_printf_x(format, va_arg(ap, unsigned int), 1));
	else if (format->spec == 'p')
		return (ft_printf_x(format, (size_t) va_arg(ap, void *), 0));
	else
		return (ft_printf_c(format, format->spec));
}

int	ft_printf(char const *str, ...)
{
	va_list		ap;
	size_t		ind;
	size_t		len;
	int			written;
	t_format	format;

	ind = 0;
	len = 0;
	va_start(ap, str);
	while (str[ind] != 0)
	{
		if (str[ind] == '%')
		{
			clean_format(&format, 1);
			set_format(str, &format, &ind);
			written = go_to_spec_function(ap, &format);
		}
		else
			written = write(1, &(str[ind ++]), 1);
		if (written < 0)
			return (-1);
		len += written;
	}
	va_end(ap);
	return (len);
}
