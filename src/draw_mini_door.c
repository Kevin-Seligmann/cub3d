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
	int		val;

	corner = &sim->minimap.corner;
	val = sim->map[(int) corner->z + y][(int) corner->x + x];
	if (val == '1')
		draw_mini_square(ged, x, y, 0x000000FF);
	else if (val == '0')
		draw_mini_square(ged, x, y, 0xFFFFFFC0);
	else if (val >= '2' && val <= '9')
		draw_mini_square(ged, x, y, 0x724dbdFF);
	else if (val == 100 || val == 200)
		draw_mini_square(ged, x, y, 0xf71109FF);
	else if (val == 150 || val == 250)
		draw_mini_square(ged, x, y, 0x08f409FF);
	else
		draw_mini_square(ged, x, y, 0xFFD600FF);
}
