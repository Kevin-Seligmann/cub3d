/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:59:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/04 21:10:46 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	When a key is pressed, a flag is set, when a key is released, the flag is
	unset. The flags permit detecting multiple key presses, executing more
	than one movement at the same time in the game loop.
*/
static void	escape_window(mlx_key_data_t keydata, void* param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(param);
	mlx_terminate(param);
}
/* 
	Keys that move to the front or back.

	W to move forwards.
	S to move backwards.
*/
static void	updown_keys(mlx_key_data_t keydata, unsigned int *key_flag)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_S;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_S;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_W;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_W;
}

/* 
	Keys that strafe ('side movement').

	A for left strafe.
	D for right strafe.
*/
static void	strafe_keys(mlx_key_data_t keydata, unsigned int *key_flag)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_A;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_A;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_D;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_D;
}

/* 
	Keys that rotate.

	Left arrow for anticlockwise rotation.
	Right arrow for clockwise rotation.
*/
static void	rotation_keys(mlx_key_data_t keydata, unsigned int *key_flag)
{
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_L;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_L;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		*key_flag &= ~CUBK_R;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		*key_flag |= CUBK_R;
}

#define todo
/*
	Casts a ray in front and detect if it hits a door.
	If it does, change it status from open/opening to closing
	or close/closing to opening.
*/
static void action_key(mlx_key_data_t keydata, t_cube *data)
{
	t_dda *dda;
	double	val;

	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
		dda = &data->dda;
		dda->x = WIDTH / 2;
		set_raycasting_data(&data->sim.player, &data->dda);
		set_step(&data->sim.player, &data->dda);
		ft_dda_door(&data->dda, data->sim.map);
		val = data->sim.map[data->dda.pos_int.z][dda->pos_int.x];
		if ((dda->side == 0 && dda->side_dist.x > 3) || \
		(dda->side == 1 && dda->side_dist.z > 3))
			return ;
		if (val == DOOR_NS || val == DOOR_WE || \
		val == DOOR_NS + 50 || val == DOOR_WE + 50)
			data->sim.map[data->dda.pos_int.z][dda->pos_int.x] ++;
		else if (val > DOOR_NS && val < DOOR_NS + 100)
			data->sim.map[data->dda.pos_int.z][dda->pos_int.x] = \
			DOOR_NS + 100 - (val - DOOR_NS);
		else if (val > DOOR_WE && val < DOOR_WE + 100)
			data->sim.map[data->dda.pos_int.z][dda->pos_int.x] = \
			DOOR_WE + 100 - (val - DOOR_WE);
	}
}

#define error
/*
	To do:
	MLX termination key
*/
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cube	*data;

	data = param;
	escape_window(keydata, data);
	rotation_keys(keydata, &data->ged.key_flag);
	strafe_keys(keydata, &data->ged.key_flag);
	updown_keys(keydata, &data->ged.key_flag);
	action_key(keydata, data);
}
