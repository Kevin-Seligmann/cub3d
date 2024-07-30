/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:00:36 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:14:12 by kseligma         ###   ########.fr       */
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
void	set_raycasting_data(t_player *player, t_dda *dda, int x)
{
	perp_clockwise_vf2(&player->dir, &dda->cam_vect);
	dda->cam_vect.x *= CAM_V_LENGTH;
	dda->cam_vect.z *= CAM_V_LENGTH;
	dda->camera_x = 2. * x / WIDTH - 1.;
	dda->ray_dir.x = player->dir.x + dda->cam_vect.x * dda->camera_x;
	dda->ray_dir.z = player->dir.z + dda->cam_vect.z * dda->camera_x;
	dda->pos_int.x = player->pos.x;
	dda->pos_int.z = player->pos.z;
	if (dda->ray_dir.x == 0)
		dda->delta_dist.x = __DBL_MAX__;
	else
		dda->delta_dist.x = fabs(1. / dda->ray_dir.x);
	if (dda->ray_dir.z == 0)
		dda->delta_dist.z = __DBL_MAX__;
	else
		dda->delta_dist.z = fabs(1. / dda->ray_dir.z);
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
static void	set_step(t_player *player, t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (player->pos.x - \
		dda->pos_int.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->pos_int.x + 1.0 - \
		player->pos.x) * dda->delta_dist.x;
	}
	if (dda->ray_dir.z < 0)
	{
		dda->step.z = -1;
		dda->side_dist.z = (player->pos.z - \
		dda->pos_int.z) * dda->delta_dist.z;
	}
	else
	{
		dda->step.z = 1;
		dda->side_dist.z = (dda->pos_int.z + 1.0 - \
		player->pos.z) * dda->delta_dist.z;
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	ft_dda(t_dda *dda, int **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
			hit = 1;
	}
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	get_wall_dist(t_dda *dda)
{
	if (dda->side == 0)
		dda->wall_dist = (dda->side_dist.x - dda->delta_dist.x);
	else
		dda->wall_dist = (dda->side_dist.z - dda->delta_dist.z);
}

#define todo
/*
	To do:
	explain this better (Probably on docs)
*/
void	ft_raycasting(t_cube *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		set_raycasting_data(&data->sim.player, &data->dda, x);
		set_step(&data->sim.player, &data->dda);
		ft_dda(&data->dda, data->sim.map);
		get_wall_dist(&data->dda);
		draw(&data->dda, &data->ged, &data->sim, x);
		x++;
	}
}
