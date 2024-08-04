/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:02:30 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/01 23:38:30 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"
# include "parser.h"

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
			data->sim.map[map_ind][line_ind]\
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
static int	alloc_map(t_sim *sim)
{
	unsigned int height;

	sim->map = malloc(sizeof(*(sim->map)) * (sim->height + 1));
	if (!sim->map)
		return (print_error(-1, MEMORY_ERROR, 0));
	sim->map[sim->height] = NULL;
	height = 0;
	while (height < sim->height)
	{
		sim->map[height] = malloc(sizeof(sim->map[height]) * (sim->width + 1));
		if (!sim->map[height])
		{
			ft_arr_free_int(sim->map);
			return (print_error(-1, MEMORY_ERROR, 0));
		}
		height ++;
	}
	return (0);
}

/*
	Sets the map width as the size of the longest line,
	counts the amount of lines to set the heigt.
	If a line is not a map line, returns error.
*/
static int	get_map_dimensions(t_cube *data, int ind)
{
	unsigned int	map_width_aux;

	data->sim.height = 0;
	data->sim.width = ft_strlen(data->parse.config_lines[ind]);
	map_width_aux = 0;
	while (data->parse.config_lines[ind])
	{
		if (is_map_line(data->parse.config_lines[ind]))
		{
			data->sim.height ++;
			map_width_aux = ft_strlen(data->parse.config_lines[ind]);
			if (map_width_aux > data->sim.width)
				data->sim.width = map_width_aux;
		}
		else
			return print_error(-1, WRONG_LINE_CONTENT, "Map");
		ind ++;
	}
	return (0);
}

/*
	Copies the map provided in the config file to its own
	array, then processes the information it contains.
*/
int	process_map(t_cube *data, int ind)
{
	if (get_map_dimensions(data, ind) == -1)
		return (-1);
	if (alloc_map(&data->sim) == -1)
		return (-1);
	copy_map(data, ind);
	if (get_map_info(&data->parse, &data->sim, data->sim.map) == -1)
	{
		ft_arr_free_int(data->sim.map);
		return (-1);
	}
	return (0);
}
