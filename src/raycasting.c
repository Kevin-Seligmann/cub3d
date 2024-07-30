/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:00:36 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	The plane vector is perpendicular to the player and has a length
	of CAM_V_LENGT (Related to FOV).

	camera.x maps '0-WIDTH' to '-1, 1'

	Ray direction is the sum of player direction and the camera (plane)
	vector multiplied by the x-camera coordinate.
	Its 'max' value is 'player direction + plane'
	It's 'min' value is 'player direction - plane'.
	So it maps 0-WIDTH to all the camera plane.
*/
void	set_raycasting_data(t_sim *map, int x)
{
	perp_clockwise_vf2(&map->player_direction, &map->cam_vect);
	map->cam_vect.x *= CAM_V_LENGTH;
	map->cam_vect.z *= CAM_V_LENGTH;
	map->camera_x.x = 2. * x / WIDTH - 1.;
	map->ray_dir.x = map->player_direction.x + map->cam_vect.x * map->camera_x.x;
	map->ray_dir.z = map->player_direction.z + map->cam_vect.z * map->camera_x.x;
	map->pos_int.x = map->player_position.x;
	map->pos_int.z = map->player_position.z;
	if (map->ray_dir.x == 0)
		map->delta_dist.x = __DBL_MAX__;
	else
		map->delta_dist.x = fabs(1. / map->ray_dir.x);
	if (map->ray_dir.z == 0)
		map->delta_dist.z = __DBL_MAX__;
	else
		map->delta_dist.z = fabs(1. / map->ray_dir.z);
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	set_step(t_sim *map)
{
	if (map->ray_dir.x < 0)
	{
		map->step.x = -1;
		map->side_dist.x = (map->player_position.x - \
		map->pos_int.x) * map->delta_dist.x;
	}
	else
	{
		map->step.x = 1;
		map->side_dist.x = (map->pos_int.x + 1.0 - \
		map->player_position.x) * map->delta_dist.x;
	}
	if (map->ray_dir.z < 0)
	{
		map->step.z = -1;
		map->side_dist.z = (map->player_position.z - \
		map->pos_int.z) * map->delta_dist.z;
	}
	else
	{
		map->step.z = 1;
		map->side_dist.z = (map->pos_int.z + 1.0 - \
		map->player_position.z) * map->delta_dist.z;
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	ft_dda(t_sim *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (map->side_dist.x < map->side_dist.z)
		{
			map->side_dist.x += map->delta_dist.x;
			map->pos_int.x += map->step.x;
			map->side = 0;
		}
		else
		{
			map->side_dist.z += map->delta_dist.z;
			map->pos_int.z += map->step.z;
			map->side = 1;
		}
		if (map->map[map->pos_int.z][map->pos_int.x] == '1')
			hit = 1;
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	get_wall_dist(t_sim *map)
{
	if (map->side == 0)
		map->wall_dist = (map->side_dist.x - map->delta_dist.x);
	else
		map->wall_dist = (map->side_dist.z - map->delta_dist.z);
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	ft_raycasting(t_cube *game)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		set_raycasting_data(&game->sim, x);
		set_step(&game->sim);
		ft_dda(&game->sim);
		get_wall_dist(&game->sim);
		draw(&game->sim, &game->ged, &game->colors, x);
		x++;
	}
}
