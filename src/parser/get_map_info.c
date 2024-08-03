/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/02 14:10:16 by kseligma         ###   ########.fr       */
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
static int	set_player_coordinates(t_sim *map, int **arr, int i, int j)
{
	if (map->player.dir.x != -2)
		return (print_error(-1, MANY_PLAYERS, 0));
	map->player.pos.x = j + 0.5;
	map->player.pos.z = i + 0.5;
	set_direction(map, arr, i, j);
	arr[i][j] = '0';
	return (0);
}

/*
	If a piece of map is not a border (an 1), checks that
	is not the limit of the map itself or any of its neighbours
	are spaces. That would entail an open map.
*/
int	square_is_enclosed(t_sim *map, int **arr, unsigned int i, unsigned int j)
{
	if (i == 0 || i == map->height - 1)
		return (print_error(-1, MAP_NOT_CLOSED, 0));
	if (j == 0 || j == map->width - 1)
		return (print_error(-1, MAP_NOT_CLOSED, 0));
	if (arr[i + 1][j] == ' ' || arr[i][j + 1] == ' ')
		return (print_error(-1, MAP_NOT_CLOSED, 0));
	if (arr[i - 1][j] == ' ' || arr[i][j - 1] == ' ')
		return (print_error(-1, MAP_NOT_CLOSED, 0));
	if ((arr[i][j] == 'O' && (arr[i + 1][j] != '1' || arr[i - 1][j] != '1')) \
	|| (arr[i][j] == 'P' && (arr[i][j + 1] != '1' || arr[i][j - 1] != '1')))
		return (print_error(-1, DOOR_NOT_CLOSED, 0));
	return (0);
}

/*
	500 to 599 and 600 to 699 are door states.
*/
static void configurate_door(t_parser *parse, unsigned int i, unsigned int j, int **map)
{
	parse->door_found = true;
	if (map[i][j] == 'O')
		map[i][j] = 500;
	else if (map[i][j] == 'P')
		map[i][j] = 600;
}

/*
	If a character that doesn't belong on a map is present, returns -1.
	If a character is a coordinate, extracts the data.
	Checks if empty spaces are enclosed.
*/
int	get_map_info(t_parser *parse, t_sim *sim, int **arr)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_strchr(" 01WESNOP", arr[i][j]))
				return (print_error(-1, WRONG_LINE_CONTENT, "Map"));
			if (ft_strchr("WESN", arr[i][j]) \
			&& set_player_coordinates(sim, arr, i, j) == -1) 
				return (-1);
			if (ft_strchr("0WESNOP", arr[i][j]) \
			&& square_is_enclosed(sim, arr, i, j) == -1)
				return (-1);
			if (ft_strchr("OP", arr[i][j]))
				configurate_door(parse, i, j, arr);
			j ++;
		}
		i ++;
	}
	return (0);
}
