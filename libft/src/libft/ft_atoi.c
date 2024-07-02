/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:01:31 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/22 11:23:33 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Spaces defined by isspace(3) (From 9 to 13 ASCII and ' ') */
int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	s = (char *) str;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s ++;
	if (*s == '-')
		sign *= -1;
	if (*s == '-' || *s == '+')
		s ++;
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + sign * (*s - 48);
		s++;
	}
	return (result);
}
