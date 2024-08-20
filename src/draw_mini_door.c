/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_door.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:26:41 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/20 21:44:09 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_mini_door(t_ged *ged, t_sim *sim, unsigned int x, unsigned int y, t_v2 *corner)
{
	if (sim->map[corner->z + y][corner->x + x] == 100 || sim->map[corner->z + y][corner->x + x] == 200)
		draw_mini_square(ged, x, y, 0xf71109FF);
	else if (sim->map[corner->z + y][corner->x + x] == 150 || sim->map[corner->z + y][corner->x + x] == 250)
		draw_mini_square(ged, x, y, 0x08f409FF);
	else
		draw_mini_square(ged, x, y, 0xFFFF00FF);
}
