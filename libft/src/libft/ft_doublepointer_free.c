/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_doublepointer_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:10:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/28 12:10:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_free(char **arr)
{
	int	ind;

	if (!arr)
		return ;
	ind = 0;
	while (arr[ind])
	{
		free(arr[ind]);
		ind ++;
	}
	free(arr);
}

void	ft_arr_free_int(int **arr)
{
	int	ind;

	if (!arr)
		return ;
	ind = 0;
	while (arr[ind])
	{
		free(arr[ind]);
		ind ++;
	}
	free(arr);
}
