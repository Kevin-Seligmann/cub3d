/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:45:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 18:33:00 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

int	set_player_coordinates(t_map *map, int **arr, int i, int j)
{
	if (map->player_direction.x != -2)
		return (print_error(-1, MANY_PLAYERS, 0));
	map->player_position.x = i;
	map->player_position.z = j;
	if (arr[i][j] == 'W')
	{
		map->player_direction.x = -1;
		map->player_direction.z = 0;
	}
	else if (arr[i][j] == 'E')
	{
		map->player_direction.x = 1;
		map->player_direction.z = 0;
	}
	else if (arr[i][j] == 'N')
	{
		map->player_direction.x = 0;
		map->player_direction.z = -1;
	}
	else if (arr[i][j] == 'S')
	{
		map->player_direction.x = 0;
		map->player_direction.z = 1;
	}
	return (0);
}

t_bool	square_is_enclosed(t_map *map, int **arr, int i, int j)
{
	if (i == 0 || i == map->width)
		return (FALSE);
	if (j == 0 || j == map->height)
		return (FALSE);
	if (arr[i + 1][j] == ' ' || arr[i][j + 1] == ' ')
		return (FALSE);
	if (arr[i - 1][j] == ' ' || arr[i][j - 1] == ' ')
		return (FALSE);
	return (TRUE);
}

t_bool	is_map_valid(t_map *map, int **arr) // Empty map?
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_strchr(" 01WESN", arr[i][j]))
				return (print_error(FALSE, WRONG_LINE_CONTENT, "Map"));
			if (ft_strchr("WESN", arr[i][j]) \
			&& set_player_coordinates(map, arr, i, j) == -1)
				return (FALSE);
			if (ft_strchr("0WESN", arr[i][j]) \
			&& square_is_enclosed(map, arr, i, j) == FALSE)
				return (print_error(FALSE, MAP_NOT_CLOSED, 0));
			j ++;
		}
		i ++;
	}
	return (TRUE);
}
