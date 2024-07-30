/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:31:23 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 12:16:14 by kseligma         ###   ########.fr       */
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
static float	movex(t_map *mapd, int **map, float movement)
{
	float	wall_offset;
	float	wall_dist;

	if (movement > 0)
		wall_offset = MIN_WALL_DIST;
	else
		wall_offset = -MIN_WALL_DIST;
	if (map[(int)(mapd->old_player_position.z)] \
	[(int)(mapd->old_player_position.x + movement + wall_offset)] == '0' &&
	map[(int)(mapd->old_player_position.z + wall_offset)] \
	[(int)(mapd->old_player_position.x + movement + wall_offset)] == '0' &&
	map[(int)(mapd->old_player_position.z - wall_offset)] \
	[(int)(mapd->old_player_position.x + movement + wall_offset)] == '0')
		return (movement);
	if (movement > 0)
		wall_dist = 1. - (mapd->old_player_position.x - \
		floorf(mapd->old_player_position.x));
	else
		wall_dist = - (mapd->old_player_position.x - \
		floorf(mapd->old_player_position.x));
	return (wall_dist * 0.9999 - wall_offset);
}

static float	movez(t_map *mapd, int **map, float movement)
{
	float	wall_offset;
	float	wall_dist;

	if (movement > 0)
		wall_offset = MIN_WALL_DIST;
	else
		wall_offset = -MIN_WALL_DIST;
	if (map[(int)(mapd->old_player_position.z + movement + wall_offset)] \
	[(int)(mapd->old_player_position.x)] == '0' &&
	map[(int)(mapd->old_player_position.z + movement + wall_offset)] \
	[(int)(mapd->old_player_position.x + wall_offset)] == '0' &&
	map[(int)(mapd->old_player_position.z + movement + wall_offset)] \
	[(int)(mapd->old_player_position.x - wall_offset)] == '0')
		return (movement);
	if (movement > 0)
		wall_dist = 1. - (mapd->old_player_position.z - \
		floorf(mapd->old_player_position.z));
	else
		wall_dist = - (mapd->old_player_position.z - \
		floorf(mapd->old_player_position.z));
	return (wall_dist * 0.9999 - wall_offset);
}

/*
	Not enough space in the main function
*/
static void	do_strafe_traslantion(int key, t_map *map)
{
	if (key & CUBK_A)
	{
		map->player_position.x += \
		movex(map, map->map, -MS * map->player_direction.z);
		map->player_position.z += \
		movez(map, map->map, MS * map->player_direction.x);
	}
	else if (key & CUBK_D)
	{
		map->player_position.x += \
		movex(map, map->map, MS * map->player_direction.z);
		map->player_position.z += \
		movez(map, map->map, -MS * map->player_direction.x);
	}
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
void	do_translation(int key, void *param)
{
	t_map	*map;

	map = param;
	map->old_player_position.x = map->player_position.x;
	map->old_player_position.z = map->player_position.z;
	if (key & CUBK_W)
	{
		map->player_position.x += \
		movex(map, map->map, MS * map->player_direction.x);
		map->player_position.z += \
		movez(map, map->map, MS * map->player_direction.z);
	}
	else if (key & CUBK_S)
	{
		map->player_position.x += \
		movex(map, map->map, -MS * map->player_direction.x);
		map->player_position.z += \
		movez(map, map->map, -MS * map->player_direction.z);
	}
	else if (key & CUBK_A || key & CUBK_D)
		do_strafe_traslantion(key, map);
}

/*
	While a key is pressed the direction vector of the player is multiplied 
	by a rotation matrix, the used angle is ROTSPEED,  -ROTSPEED.

	cos(a)	- sin(a)
	sin(a)	cos(a)
*/
void	do_rotation(int key, void *param)
{
	t_map	*map;
	float	aux;

	map = param;
	if (key & CUBK_L)
	{
		aux = map->player_direction.x;
		map->player_direction.x = aux * cos(ROTSPEED) - \
		map->player_direction.z * sin(ROTSPEED);
		map->player_direction.z = aux * sin(ROTSPEED) + \
		map->player_direction.z * cos(ROTSPEED);
	}
	if (key & CUBK_R)
	{
		aux = map->player_direction.x;
		map->player_direction.x = aux * cos(-ROTSPEED) - \
		map->player_direction.z * sin(-ROTSPEED);
		map->player_direction.z = aux * sin(-ROTSPEED) + \
		map->player_direction.z * cos(-ROTSPEED);
	}
}
