/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:34:38 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 18:35:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

void debug_print_data(t_cube *data)
{
	ft_printf("Ceiling %d %d %d\n", data->elements.ceiling_color.x, data->elements.ceiling_color.y, data->elements.ceiling_color.z);
	ft_printf("Floor %d %d %d\n", data->elements.floor_color.x, data->elements.floor_color.y, data->elements.floor_color.z);
	ft_printf("North text %p South text %p East text %p West text %p \n",\
	data->ged.textures.north_wall, data->ged.textures.south_wall, data->ged.textures.east_wall, data->ged.textures.west_wall);
	printf("Player dir %.2f %.2f Player pos %.2f %.2f\n", data->map.player_direction.x,  data->map.player_direction.z,  data->map.player_position.x, data->map.player_position.z);
	ft_printf("Map %d x %d \n", data->map.width, data->map.height);
	int **map = data->map.map;
	while (map && *map)
	{
		int *line = *map;
		while (line && *line)
		{
			ft_printf("%c", *line);
			line ++;
		}
		ft_printf("%c", '\n');
		map ++;
	}
}

t_bool	obligatory_elements_are_set(t_cube *data)
{
	if (data->ged.textures.north_wall == 0 || \
		data->ged.textures.south_wall == 0 || \
		data->ged.textures.east_wall == 0 || \
		data->ged.textures.west_wall == 0 || \
		data->elements.ceiling_color.x == -1 || \
		data->elements.floor_color.x == -1 || \
		data->elements.ceiling_color.y == -1 || \
		data->elements.floor_color.y == -1 || \
		data->elements.ceiling_color.z == -1 || \
		data->elements.floor_color.z == -1 || \
		data->map.player_direction.x == -2 || \
		data->map.player_direction.z == -2 || \
		data->map.player_position.x == -2 || \
		data->map.player_position.z == -2)
		return (FALSE);
	return (TRUE);
}

void	set_default_config(t_cube *data)
{
	data->ged.textures.north_wall = 0;
	data->ged.textures.south_wall = 0;
	data->ged.textures.east_wall = 0;
	data->ged.textures.west_wall = 0;
	data->elements.ceiling_color.x = -1;
	data->elements.floor_color.x = -1;
	data->elements.ceiling_color.y = -1;
	data->elements.floor_color.y = -1;
	data->elements.ceiling_color.z = -1;
	data->elements.floor_color.z = -1;
	data->map.player_direction.x = -2;
	data->map.player_direction.z = -2;
	data->map.player_position.x = -2;
	data->map.player_position.z = -2;
}

int	parse_file_config(t_cube *data)
{
	char	*line;

	line = NULL;
	set_default_config(data);
	while (read_next_line(data->files.config_file_fd, &line) && is_map_line(line) == FALSE) // Should a line of just spaces be considered empty? Not for now
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
	return (0);
}

int	parser(t_cube *data, int argc, char **argv)
{
	if (argc != 2)
		return (print_error(-1, INVALID_NUMBER_ARGS, 0));
	data->files.config_file_path = argv[1];
	if (open_file(data->files.config_file_path, &data->files.config_file_fd) == -1)
		return (-1);
	if (parse_file_config(data) == -1){ // Close fd
		debug_print_data(data); // debug
		return (-1);
	}
	debug_print_data(data); // debug
	return (0);
}
