/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:37:40 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/21 16:39:13 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	If a piece of map is not a border (an 1), checks that
	is not the limit of the map itself or any of its neighbours
	are spaces. That would entail an open map.
*/
void	check_square_enclosed(t_cube *data,
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
