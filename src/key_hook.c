/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:59:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	When a key is pressed, a flag is set, when a key is released, the flag is
	unset. The flags permit detecting multiple key presses, executing more
	than one movement at the same time in the game loop.
*/

/* 
	Keys that move to the front or back.

	W to move forwards.
	S to move backwards.
*/
static void	updown_keys(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_S;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_S;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_W;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_W;
}

/* 
	Keys that strafe ('side movement').

	A for left strafe.
	D for right strafe.
*/
static void	strafe_keys(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_A;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_A;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_D;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_D;
}

/* 
	Keys that rotate.

	Left arrow for anticlockwise rotation.
	Right arrow for clockwise rotation.
*/
static void	rotation_keys(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_L;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_L;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		data->sim.key_flag &= ~CUBK_R;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		data->sim.key_flag |= CUBK_R;
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
	rotation_keys(keydata, data);
	strafe_keys(keydata, data);
	updown_keys(keydata, data);
}
