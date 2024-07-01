/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:29:44 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/23 17:35:12 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_length(char **arr, char *sep, size_t n)
{
	size_t	len_p_s;
	size_t	i_p_s;

	i_p_s = 0;
	len_p_s = 0;
	while (i_p_s < n)
	{
		len_p_s += ft_strlen(arr[i_p_s]);
		i_p_s ++;
	}
	return (len_p_s + ft_strlen(sep) * (n - 1));
}

char	*ft_strsnjoin(char **arr, char *sep, size_t n)
{
	char	*s;
	size_t	i_p_s;
	size_t	i_s;
	size_t	len_sep;
	size_t	len_s;

	if (!arr || !sep || n < 1)
		return (0);
	s = ft_lastloc(total_length(arr, sep, n) + 1, sizeof(*s));
	if (!s)
		return (0);
	len_sep = ft_strlen(sep);
	i_p_s = 0;
	i_s = 0;
	while (i_p_s < n && arr[i_p_s])
	{
		len_s = ft_strlen(arr[i_p_s]);
		ft_memmove(&(s[i_s]), arr[i_p_s], len_s);
		i_s += len_s;
		if (++ i_p_s < n)
			ft_memmove(&(s[i_s]), sep, len_sep);
		if (i_p_s < n)
			i_s += len_sep;
	}
	return (s);
}
