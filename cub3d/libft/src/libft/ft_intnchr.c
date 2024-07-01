/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:37:43 by kseligma          #+#    #+#             */
/*   Updated: 2024/02/26 14:37:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_intnchr(int *arr, int c, int n)
{
	int	ind;

	ind = 0;
	while (ind < n)
	{
		if (arr[ind] == c)
			return (&(arr[ind]));
		ind ++;
	}
	return (0);
}
