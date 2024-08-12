/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:29:43 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/07 13:37:32 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	update_size(t_ged *ged)
{
	if (ged->img->width != (unsigned int) ged->mlx->width || \
	ged->img->height != (unsigned int) ged->mlx->height)
		mlx_resize_image(ged->img, ged->mlx->width, ged->mlx->height);
}
