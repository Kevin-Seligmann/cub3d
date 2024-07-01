/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 08:25:10 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/17 16:02:53 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_format
{
	char	spec;
	char	plus;
	char	minus;
	char	space;
	char	hashtag;
	char	mayus;
	char	pad_char;
	int		width;
	int		precision;
	int		str_len;
	int		extra_len;
}	t_format;

int		ft_printf(char const *str, ...);
int		ft_printf_c(t_format *format, unsigned char c);
int		ft_printf_s(t_format *format, char *s);
int		ft_printf_dec(t_format *format, long dec);
int		ft_printf_x(t_format *format, size_t hex, char mayus);
int		prefix_hex(t_format *f, int mayus, size_t hex);
int		prefix_signed(t_format *f, long num);
int		ft_printf_precision(t_format *f, int pad_size);
int		ft_printf_pad(t_format *f, int pad_size, char pad_char);
int		ft_printf_right_hex(t_format *f, char *str, size_t hex, char mayus);
int		ft_printf_right_dec(t_format *f, char *str, long dec);
int		ft_printf_left_hex(t_format *f, char *str, size_t hex, char mayus);
int		ft_printf_left_dec(t_format *f, char *str, long dec);
char	*ft_itoa_base(size_t n, char *base);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
