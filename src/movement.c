/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:31:23 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:32:09 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#define todo
/*
	To do:
	Improve collision to not get stuck in corners. 
	hint: Sometimes the character gets inside the wall

	If the place to move is inside the collision, returns the distance
	to the wall. Otherwise returns the movement itself.

	'return (wall_dist * 0.9999 - wall_offset);'. Getting too
	close to the wall could result in rounding errors,
	glitching the player inside and causing bounces.
*/
static float	movex(t_player *player, int **map, double movement)
{
	float	wall_offset;
	float	wall_dist;

	if (movement > 0)
		wall_offset = MIN_WALL_DIST;
	else
		wall_offset = -MIN_WALL_DIST;
	if (map[(int)(player->old_pos.z)] \
	[(int)(player->old_pos.x + movement + wall_offset)] == '0' &&
	map[(int)(player->old_pos.z + wall_offset)] \
	[(int)(player->old_pos.x + movement + wall_offset)] == '0' &&
	map[(int)(player->old_pos.z - wall_offset)] \
	[(int)(player->old_pos.x + movement + wall_offset)] == '0')
		return (movement);
	if (movement > 0)
		wall_dist = 1. - (player->old_pos.x - floor(player->old_pos.x));
	else
		wall_dist = - (player->old_pos.x - floor(player->old_pos.x));
	return (wall_dist * 0.9999 - wall_offset);
}

static float	movez(t_player *player, int **map, double movement)
{
	float	wall_offset;
	float	wall_dist;

	if (movement > 0)
		wall_offset = MIN_WALL_DIST;
	else
		wall_offset = -MIN_WALL_DIST;
	if (map[(int)(player->old_pos.z + movement + wall_offset)] \
	[(int)(player->old_pos.x)] == '0' &&
	map[(int)(player->old_pos.z + movement + wall_offset)] \
	[(int)(player->old_pos.x + wall_offset)] == '0' &&
	map[(int)(player->old_pos.z + movement + wall_offset)] \
	[(int)(player->old_pos.x - wall_offset)] == '0')
		return (movement);
	if (movement > 0)
		wall_dist = 1. - (player->old_pos.z - floor(player->old_pos.z));
	else
		wall_dist = - (player->old_pos.z - floor(player->old_pos.z));
	return (wall_dist * 0.9999 - wall_offset);
}

#define suggestion
/*
	Suggestion:
	Try to combine usual movement and strafe without bugs

	Old player position is stored to not give priority to any direction.
	If not, z movement will be calculated from the new x position. This
	could cause inconsistency close to walls.

	To move forwards add and backwards add the direction vector to the
	position, multiplied by MS (Or its negative).

	To move left and right, do the same but with perpendicular vectors
	the two directions will be (y, -x) and (-y, x).
*/
void	do_translation(t_player *player, int **map, unsigned int key_flag)
{
	player->old_pos.x = player->pos.x;
	player->old_pos.z = player->pos.z;
	if (key_flag & CUBK_W)
	{
		player->pos.x += movex(player, map, MS * player->dir.x);
		player->pos.z += movez(player, map, MS * player->dir.z);
	}
	else if (key_flag & CUBK_S)
	{
		player->pos.x += movex(player, map, -MS * player->dir.x);
		player->pos.z += movez(player, map, -MS * player->dir.z);
	}
	else if (key_flag & CUBK_A)
	{
		player->pos.x += movex(player, map, -MS * player->dir.z);
		player->pos.z += movez(player, map, MS * player->dir.x);
	}
	else if (key_flag & CUBK_D)
	{
		player->pos.x += movex(player, map, MS * player->dir.z);
		player->pos.z += movez(player, map, -MS * player->dir.x);
	}
}

/*
	While a key is pressed the direction vector of the player is multiplied 
	by a rotation matrix, the used angle is ROTSPEED,  -ROTSPEED.

	cos(a)	- sin(a)
	sin(a)	cos(a)
*/
void	do_rotation(t_player *player, int unsigned key_flag)
{
	double	aux;

	if (key_flag & CUBK_L)
	{
		aux = player->dir.x;
		player->dir.x = aux * cos(ROTSPEED) - \
		player->dir.z * sin(ROTSPEED);
		player->dir.z = aux * sin(ROTSPEED) + \
		player->dir.z * cos(ROTSPEED);
	}
	if (key_flag & CUBK_R)
	{
		aux = player->dir.x;
		player->dir.x = aux * cos(-ROTSPEED) - \
		player->dir.z * sin(-ROTSPEED);
		player->dir.z = aux * sin(-ROTSPEED) + \
		player->dir.z * cos(-ROTSPEED);
	}
}
