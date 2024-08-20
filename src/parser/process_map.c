/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:02:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 11:59:06 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Copies each map line from the config file to the double array
*/
static void	copy_map(t_cube *data, unsigned int ind)
{
	unsigned int	line_ind;
	unsigned int	map_ind;

	map_ind = 0;
	while (data->parse.config_lines[ind])
	{
		line_ind = 0;
		while (data->parse.config_lines[ind][line_ind])
		{
			data->sim.map[map_ind][line_ind] \
			= data->parse.config_lines[ind][line_ind];
			line_ind ++;
		}
		while (line_ind < data->sim.width)
		{
			data->sim.map[map_ind][line_ind] = ' ';
			line_ind ++;
		}
		data->sim.map[map_ind][line_ind] = 0;
		map_ind ++;
		ind ++;
	}
}

/*
	Allocates a double array to store the map.
*/
static void	alloc_map(t_cube *data, t_sim *sim)
{
	unsigned int	height;

	sim->map = malloc(sizeof(*(sim->map)) * (sim->height + 1));
	if (!sim->map)
		exit_cubed(data, -1, MEMORY_ERROR, 0);
	sim->map[sim->height] = NULL;
	height = 0;
	while (height < sim->height)
	{
		sim->map[height] = malloc(sizeof(sim->map[height]) * (sim->width + 1));
		if (!sim->map[height])
			exit_cubed(data, -1, MEMORY_ERROR, 0);
		height ++;
	}
}

/*
	Sets the map width as the size of the longest line,
	counts the amount of lines to set the heigt.
	If a line is not a map line, returns error.
*/
static void	get_map_dimensions(t_cube *data, int ind)
{
	size_t	map_width_aux;

	data->sim.height = 0;
	data->sim.width = ft_strlen(data->parse.config_lines[ind]);
	map_width_aux = 0;
	while (data->parse.config_lines[ind])
	{
		data->sim.height ++;
		map_width_aux = ft_strlen(data->parse.config_lines[ind]);
		if (map_width_aux > (size_t) data->sim.width)
			data->sim.width = map_width_aux;
		if (map_width_aux > MAX_MAP_WIDTH || data->sim.height > MAX_MAP_HEIGHT)
			exit_cubed(data, -1, MAP_DIMENSIONS_ERROR, 0);
		ind ++;
	}
}

/*
	Copies the map provided in the config file to its own
	array, then processes the information it contains.
*/
void	process_map(t_cube *data, int ind)
{
	get_map_dimensions(data, ind);
	alloc_map(data, &data->sim);
	copy_map(data, ind);
	get_map_info(data, &data->parse, &data->sim, data->sim.map);
}
