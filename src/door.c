/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:56:24 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/04 21:01:13 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_dda_door(t_dda *dda, int **map)
{
	dda->door_hit = false;
	while (!dda->door_hit)
	{
		if (dda->side_dist.x < dda->side_dist.z)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->pos_int.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.z += dda->delta_dist.z;
			dda->pos_int.z += dda->step.z;
			dda->side = 1;
		}
		if (map[dda->pos_int.z][dda->pos_int.x] == '1')
			break;
		else if (map[dda->pos_int.z][dda->pos_int.x] < DOOR_WE + 100 \
		&& map[dda->pos_int.z][dda->pos_int.x] > DOOR_NS - 1)
			dda->door_hit = true;
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void check_door_side(t_dda *dda, int **map)
{
	dda->door_side = \
	(dda->side == 1 && dda->step.z == 1 && dda->pos_int.z > 0 \
	&& map[dda->pos_int.z - 1][dda->pos_int.x] > DOOR_NS - 1 \
	&& map[dda->pos_int.z - 1][dda->pos_int.x] < DOOR_NS + 100) || \
	(dda->side == 1 && dda->step.z == -1 && \
	map[dda->pos_int.z + 1] && \
	map[dda->pos_int.z + 1][dda->pos_int.x] > DOOR_NS - 1 && \
	map[dda->pos_int.z + 1][dda->pos_int.x] < DOOR_NS + 100) || \
	(dda->side == 0 && dda->step.x == 1  && dda->pos_int.x > 0 \
	&& map[dda->pos_int.z][dda->pos_int.x - 1] > DOOR_WE - 1 \
	&& map[dda->pos_int.z][dda->pos_int.x - 1] < DOOR_WE + 100) || \
	(dda->side == 0 && dda->step.x == -1 && \
	map[dda->pos_int.z][dda->pos_int.x + 1] > DOOR_WE - 1 &&
	map[dda->pos_int.z][dda->pos_int.x + 1] < DOOR_WE + 100);
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void get_door_offset(t_dda *dda, int value)
{
	if (value > DOOR_NS - 1 && value < DOOR_NS + 51)
		dda->door_offset = (value - 100.) / 50.;
	else if (value > DOOR_NS - 1 && value < DOOR_NS + 100)
		dda->door_offset = 1 - (value - (DOOR_NS + 50)) / 50.;
	else if (value > DOOR_WE - 1 && value < DOOR_WE + 51)
		dda->door_offset = (value - DOOR_WE) / 50.;
	else if (value > DOOR_WE + 50 && value < DOOR_WE + 100)
		dda->door_offset = 1 - (value - (DOOR_WE + 50)) / 50.;
	else
		dda->door_offset = 0;
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void check_door_hit(t_dda *dda, t_player *player, int **map, int *hit)
{
	get_door_offset(dda, map[dda->pos_int.z][dda->pos_int.x]);
	if (dda->side == 1)
	{
		dda->door_x = player->pos.x + dda->ray_dir.x * (dda->side_dist.z - \
		dda->delta_dist.z) + dda->step.z * \
		dda->ray_dir.x / (dda->ray_dir.z * 2.);
		if (dda->door_x - dda->pos_int.x < 1. && \
		dda->door_x - dda->door_offset - dda->pos_int.x > 0.)
		{
			*hit = 1;
			dda->door_hit = true;
		}
	}
	if (dda->side == 0)
	{
		dda->door_x = player->pos.z + dda->ray_dir.z * (dda->side_dist.x - \
		dda->delta_dist.x) + dda->step.x * \
		dda->ray_dir.z / (dda->ray_dir.x * 2.);
		if (dda->door_x - dda->pos_int.z < 1. && \
		dda->door_x - dda->door_offset - dda->pos_int.z > 0.)
		{
			*hit = 1;
			dda->door_hit = true;
		}
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void update_doors(t_cube *data, int **map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < data->sim.height)
	{
		x = 0;
		while (x < data->sim.width)
		{
			if (map[y][x] == DOOR_NS + 99)
				map[y][x] = DOOR_NS;
			else if ((map[y][x] > DOOR_NS && map[y][x] < DOOR_NS + 50) || \
			(map[y][x] > DOOR_NS + 50 && map[y][x] < DOOR_NS + 99))
				map[y][x] ++;
			else if (map[y][x] == DOOR_WE + 99)
				map[y][x] = DOOR_WE;
			else if ((map[y][x] > DOOR_WE && map[y][x] < DOOR_WE + 50) || \
			(map[y][x] > DOOR_WE + 50 && map[y][x] < DOOR_WE + 99))
				map[y][x] ++;

			x ++;
		}
		y ++;
	}
}
