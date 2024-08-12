/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 03:06:39 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/12 22:19:57 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_mini_map(t_dda *dda, t_ged *ged, t_sim *sim)
{
	unsigned int	x;
	unsigned int	y;
	
	(void)dda;
	y = 0;
	while (y < sim->height)
	{
		x = 0;
		while (x < sim->width)
		{
			if (sim->map[y][x] == '1')
				mlx_put_pixel(ged->minimap, x, y, 0xFFFF00F0);
			else
				mlx_put_pixel(ged->minimap, x, y, 0x0000FFF0);
			x++;
		}
		y++;
	}
}
