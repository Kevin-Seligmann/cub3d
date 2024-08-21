/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:26:41 by oseivane          #+#    #+#             */
/*   Updated: 2024/08/21 16:29:39 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_square(t_ged *ged, t_sim *sim, unsigned int x, unsigned int y)
{
	t_v2	*corner;

	corner = &sim->minimap.corner;
	if (sim->map[corner->z + y][corner->x + x] == '1')
		draw_mini_square(ged, x, y, 0xFFFFFFFF);
	else if (sim->map[corner->z + y][corner->x + x] == '0')
		draw_mini_square(ged, x, y, 0xFFFFFFC0);
	else if (sim->map[corner->z][corner->x] >= '2' \
		|| sim->map[corner->z][corner->x] <= '9')
		draw_mini_square(ged, x, y, 0x724dbdFF);
	else if (sim->map[corner->z + y][corner->x + x] == 100 \
	|| sim->map[corner->z + y][corner->x + x] == 200)
		draw_mini_square(ged, x, y, 0xf71109FF);
	else if (sim->map[corner->z + y][corner->x + x] == 150 \
	|| sim->map[corner->z + y][corner->x + x] == 250)
		draw_mini_square(ged, x, y, 0x08f409FF);
}
