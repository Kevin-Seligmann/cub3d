/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 18:04:53 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Sets direction.
*/
static void	set_direction(t_sim *map, int **arr, int i, int j)
{
	if (arr[i][j] == 'W')
	{
		map->player.dir.x = -1;
		map->player.dir.z = 0;
	}
	else if (arr[i][j] == 'E')
	{
		map->player.dir.x = 1;
		map->player.dir.z = 0;
	}
	else if (arr[i][j] == 'N')
	{
		map->player.dir.x = 0;
		map->player.dir.z = -1;
	}
	else if (arr[i][j] == 'S')
	{
		map->player.dir.x = 0;
		map->player.dir.z = 1;
	}
}

/*
	If the position has been set, returns error.

	Otherwise places the player in the middle of the block, and its direction
	accordingly.
*/
static void	set_player_coordinates(t_cube *data, t_sim *map, int i, int j)
{
	if (map->player.dir.x != -2)
		exit_cubed(data, -1, MANY_PLAYERS, 0);
	map->player.pos.x = j + 0.5;
	map->player.pos.z = i + 0.5;
	set_direction(map, map->map, i, j);
	map->map[i][j] = '0';
}

/*
	If a piece of map is not a border (an 1), checks that
	is not the limit of the map itself or any of its neighbours
	are spaces. That would entail an open map.
*/
static void	check_square_enclosed(t_cube *data,
			t_sim *map, unsigned int i, unsigned int j)
{
	if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
		exit_cubed(data, -1, MAP_NOT_CLOSED, 0);
	if (map->map[i + 1][j] == ' ' || map->map[i][j + 1] == ' ')
		exit_cubed(data, -1, MAP_NOT_CLOSED, 0);
	if (map->map[i - 1][j] == ' ' || map->map[i][j - 1] == ' ')
		exit_cubed(data, -1, MAP_NOT_CLOSED, 0);
	if ((map->map[i][j] == 'O' && (map->map[i + 1][j] != '1'
		|| map->map[i - 1][j] != '1')) || (map->map[i][j] == 'P'
		&& (map->map[i][j + 1] != '1' || map->map[i][j - 1] != '1')))
		exit_cubed(data, -1, DOOR_NOT_CLOSED, 0);
}

/*
	Sets door state to close. Tells if door or spray has been found.
*/
static void	config_door(t_parser *parse, \
unsigned int i, unsigned int j, int **map)
{
	if (ft_strchr("OP", map[i][j]))
	{
		parse->door_found = true;
		if (map[i][j] == 'O')
			map[i][j] = DOOR_NS;
		else if (map[i][j] == 'P')
			map[i][j] = DOOR_WE;
	}
}

void	config_sprite(t_cube *data, int i, int j, int **map)
{
	int	ind;

	if (data->dda.sprite.sprite_count == 29)
		exit_cubed(data, -1, SPRITE_LIMIT, 0);
	data->dda.sprite.sprites[data->dda.sprite.sprite_count].pos.x = j + 0.5;
	data->dda.sprite.sprites[data->dda.sprite.sprite_count].pos.z = i + 0.5;
	data->dda.sprite.sprites[data->dda.sprite.sprite_count].sprite_ind = \
	map[i][j] - '2';
	ind = '2';
	while (ind < '9' + 1)
	{
		if (map[i][j] == ind)
			data->parse.sprite_found[ind - '2'] = true;
		ind ++;
	}
	data->dda.sprite.sprite_count ++;
}

/*
	If a character that doesn't belong on a map is present, returns -1.
	If a character is a coordinate, extracts the data.
	Checks if empty spaces are enclosed.
*/
void	get_map_info(t_cube *data, t_parser *parse, t_sim *sim, int **arr)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (!ft_strchr(" 0123456789WESNOP", arr[i][j]))
				exit_cubed(data, -1, WRONG_LINE_CONTENT, "Map");
			if (ft_strchr("WESN", arr[i][j]))
				set_player_coordinates(data, sim, i, j);
			if (ft_strchr("023456789WESNOP", arr[i][j]))
				check_square_enclosed(data, sim, i, j);
			if (ft_strchr("OP", arr[i][j]))
				config_door(parse, i, j, arr);
			if (ft_strchr("23456789", arr[i][j]))
				config_sprite(data, i, j, arr);
		}
	}
}
