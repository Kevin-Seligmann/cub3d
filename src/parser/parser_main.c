/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:34:38 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:58 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

// Debug function, delete eventually
void debug_print_data(t_cube *data)
{
	ft_printf("Ceiling %d %d %d\n", data->colors.ceiling_color.x, data->colors.ceiling_color.y, data->colors.ceiling_color.z);
	ft_printf("Floor %d %d %d\n", data->colors.floor_color.x, data->colors.floor_color.y, data->colors.floor_color.z);
	ft_printf("North text %p South text %p East text %p West text %p \n",\
	data->ged.textures.north_wall, data->ged.textures.south_wall, data->ged.textures.east_wall, data->ged.textures.west_wall);
	printf("Player dir %.2f %.2f Player pos %.2f %.2f\n", data->sim.player_direction.x,  data->sim.player_direction.z,  data->sim.player_position.x, data->sim.player_position.z);
	ft_printf("Map %d x %d \n", data->sim.width, data->sim.height);
	int **map = data->sim.map;
	while (map && *map)
	{
		int *line = *map;
		while (line && *line)
		{
			ft_printf("%c", *line);
			line++;
		}
		ft_printf("%c", '\n');
		map++;
	}
}

/*
	Copies the information stored in the config file to a
	double char array
*/
static int	copy_file_to_tab(t_parser *parse_data)
{
	char	*line;
	char	*aux;

	parse_data->config = NULL;
	line = get_next_line(parse_data->fd);
	while (line)
	{
		aux = parse_data->config;
		parse_data->config = ft_strjoin(aux, line);
		free(aux);
		free(line);
		if (!parse_data->config)
			return (print_error(-1, MEMORY_ERROR, 0));
		line = get_next_line(parse_data->fd);
	}
	parse_data->config_lines = ft_split(parse_data->config, '\n');
	if (!parse_data->config_lines)
		return (print_error(-1, MEMORY_ERROR, 0));
	return (0);
}

/*
	Parser main.

	Checks the extension is correct, copies the content of the file
	in a char**, processes the configuration.
*/
int	parser(t_cube *data, int argc, char **argv)
{
	int	error_value;

	if (argc != 2)
		return (print_error(-1, INVALID_NUMBER_ARGS, 0));
	if (extension_checker(argv[1], CONFIG_FILE_EXTENSION) == -1)
		return (-1);
	data->parse_data.fd = open(argv[1], O_RDWR);
	if (data->parse_data.fd == -1)
		return (print_error(-1, argv[1], strerror(errno)));
	error_value = copy_file_to_tab(&data->parse_data);
	close(data->parse_data.fd);
	free(data->parse_data.config);
	if (error_value == -1)
		return (-1);
	error_value = process_file_config(data);
	ft_arr_free(data->parse_data.config);
	if (error_value == -1)
		return (-1);
	return (0);
}
