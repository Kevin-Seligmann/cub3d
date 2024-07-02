/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:42:50 by kseligma          #+#    #+#             */
/*   Updated: 2024/01/14 18:33:32 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	ind;

	if (!f)
		return ;
	ind = 0;
	while (s[ind])
	{
		f(ind, &(s[ind]));
		ind ++;
	}
}
