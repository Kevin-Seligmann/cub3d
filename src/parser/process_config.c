/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:28:57 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/19 17:41:48 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cubed.h"

/*
	Splits the line by spaces.

	If the identifier is a texture, parses a texture.
	If the identifier is a color, parses a color.
	If is neither there's an error on the file, prints and returns -1.
*/
static void	process_element(t_cube *data, char *line)
{
	char	**args;
	int		err;

	args = ft_split(line, ' ');
	if (!args)
		exit_cubed(data, -1, MEMORY_ERROR, 0);
	if (!ft_strcmp(args[0], EAST_ID) || \
		!ft_strcmp(args[0], WEST_ID) || \
		!ft_strcmp(args[0], NORTH_ID) || \
		!ft_strcmp(args[0], SOUTH_ID) || \
		!ft_strcmp(args[0], DOOR_ID))
		err = get_texture(data, args);
	else if (!ft_strcmp(args[0], FLOOR_ID) || \
		!ft_strcmp(args[0], CEILING_ID))
		err = get_map_color(data, args, line);
	else if (is_sprite_id(args[0]))
		err = get_sprite_texture(data, args);
	else
		err = print_error(-1, WRONG_LINE_CONTENT, 0);
	ft_arr_free(args);
	if (err == -1)
		exit_cubed(data, -1, 0, 0);
}

/*
	If any of the configuration that has to be found on the config file is
	not present, returns false. Otherwise true.
*/
static bool	obligatory_elements_are_set(t_cube *data)
{
	if (data->ged.textures.north_wall == 0 || \
		data->ged.textures.south_wall == 0 || \
		data->ged.textures.east_wall == 0 || \
		data->ged.textures.west_wall == 0 || \
		data->sim.ceiling_color == 0 || \
		data->sim.floor_color == 0 || \
		data->sim.player.pos.x == -2 || \
		data->sim.player.pos.z == -2 || \
		data->sim.player.dir.x == -2 || \
		data->sim.player.dir.z == -2 || \
		(data->parse.door_found == true && \
		(data->ged.textures.door == 0 || \
		data->ged.textures.door_side == 0)) || \
		found_sprite_is_not_set(data))
		return (false);
	return (true);
}

/*
	Initializes some data to impossible values to have in config.
	Color can be 0 because color data is RGBA and config file only accepts
	RGB. (Minimum color, black, is 0xff).
*/
static void	set_default_config(t_cube *data)
{
	data->ged.textures.north_wall = 0;
	data->ged.textures.south_wall = 0;
	data->ged.textures.east_wall = 0;
	data->ged.textures.west_wall = 0;
	data->ged.textures.door = 0;
	data->ged.textures.door_side = 0;
	data->sim.ceiling_color = 0;
	data->sim.floor_color = 0;
	data->sim.player.dir.x = -2;
	data->sim.player.dir.z = -2;
	data->sim.player.pos.x = -2;
	data->sim.player.pos.z = -2;
}

/*
	Loops through all lines until it finds a map line.
	The rest of the file is considered part of the map.
	If there are elements lacking or there's any error, returns -1.
*/
void	process_file_config(t_cube *data)
{
	int		ind;

	set_default_config(data);
	ind = 0;
	while (is_map_line(data->parse.config_lines[ind]) == false)
	{
		process_element(data, data->parse.config_lines[ind]);
		ind ++;
	}
	process_map(data, ind);
	if (obligatory_elements_are_set(data) == false)
		exit_cubed(data, -1, MISSING_CONFIG_DATA, 0);
}
