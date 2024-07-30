/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:57 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:50:14 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cubed.h"

// Checks if the obligatory values are set (E.g, if there's color)
t_bool	obligatory_elements_are_set(t_cube *data)
{
	if (data->ged.textures.north_wall == 0 || \
		data->ged.textures.south_wall == 0 || \
		data->ged.textures.east_wall == 0 || \
		data->ged.textures.west_wall == 0 || \
		data->colors.ceiling_color.x == -1 || \
		data->colors.floor_color.x == -1 || \
		data->colors.ceiling_color.y == -1 || \
		data->colors.floor_color.y == -1 || \
		data->colors.ceiling_color.z == -1 || \
		data->colors.floor_color.z == -1 || \
		data->sim.player_direction.x == -2 || \
		data->sim.player_direction.z == -2 || \
		data->sim.player_position.x == -2 || \
		data->sim.player_position.z == -2)
		return (FALSE);
	return (TRUE);
}

// Set default value, equivalent to something not set
void	set_default_config(t_cube *data)
{
	data->ged.textures.north_wall = 0;
	data->ged.textures.south_wall = 0;
	data->ged.textures.east_wall = 0;
	data->ged.textures.west_wall = 0;
	data->colors.ceiling_color.x = -1;
	data->colors.floor_color.x = -1;
	data->colors.ceiling_color.y = -1;
	data->colors.floor_color.y = -1;
	data->colors.ceiling_color.z = -1;
	data->colors.floor_color.z = -1;
	data->sim.player_direction.x = -2;
	data->sim.player_direction.z = -2;
	data->sim.player_position.x = -2;
	data->sim.player_position.z = -2;
}

// Parses the configuration file given as input
int	process_file_config(t_cube *data)
{
	char	*line;

	line = NULL;
	set_default_config(data);
	while (read_next_line(data->parse_data.fd, &line) && is_map_line(line) == FALSE) // Should a line of just spaces be considered empty?
	{
		if (parse_element(data, line) == -1)
		{
			free(line);
			return (-1);
		}
	}
	if (!line)
		return (print_error(-1, NO_MAP_FOUND, 0));
	if (parse_map(data, line) == -1)
		return (-1);
	if (obligatory_elements_are_set(data) == FALSE)
		return (print_error(-1, MISSING_CONFIG_DATA, 0)); // Free map
	data->colors.ceiling_color = get_rgba(data->colors.ceiling_color.x, data->colors.ceiling_color.y, data->colors.ceiling_color.z, 0xff);
	data->colors.floor_color = get_rgba(data->colors.floor_color.x, data->colors.floor_color.y, data->colors.floor_color.z, 0xff);
	return (0);
}
