/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:34:38 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 16:16:55 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

bool	is_map_line_char_p(char *line, int ind)
{
	bool	is_map;
	bool	found_space;

	if (!line[ind])
		return (false);
	found_space = false;
	while (line[ind] == ' ')
	{
		(ind)++;
		found_space = true;
	}
	is_map = line[ind] == '1' || (found_space && (line[ind] == '\n' || !line[ind]));
	return (is_map);
}

static void	empty_after_map(t_cube *data, char *line)
{
	int		ind;

	ind = 0;
	while (!is_map_line_char_p(line, ind))
	{
		while (line[ind] != '\n' && line[ind])
			ind++;
		if (line[ind] == '\n')
			ind ++;
		if (!line[ind])
			exit_cubed(data, -1, "Map not found", 0);
	}
	while (is_map_line_char_p(line, ind))
	{
		while (line[ind] != '\n' && line[ind])
			ind++;
		if (line[ind] == '\n')
			ind ++;
	}
	if (line[ind])
		exit_cubed(data, -1, WRONG_LINE_CONTENT, "After map");
}

/*
	Copies the information stored in the config file to a
	double char array
*/
static void	copy_file_to_tab(t_cube *data, t_parser *parse_data)
{
	char	*line;
	char	*aux;

	parse_data->config = ft_calloc(1, sizeof(char *));
	if (!parse_data->config)
		exit_cubed(data, -1, MEMORY_ERROR, 0);
	line = get_next_line(parse_data->fd);
	while (line)
	{
		aux = parse_data->config;
		parse_data->config = ft_strjoin(aux, line);
		free(aux);
		free(line);
		if (!parse_data->config)
			exit_cubed(data, -1, MEMORY_ERROR, 0);
		line = get_next_line(parse_data->fd);
	}
	empty_after_map(data, parse_data->config);
	parse_data->config_lines = ft_split(parse_data->config, '\n');
	if (!parse_data->config_lines)
		exit_cubed(data, -1, MEMORY_ERROR, 0);
}

/*
	Parser main.

	Checks the extension is correct, copies the content of the file
	in a char**, processes the configuration.
*/
void	parser(t_cube *data, int argc, char **argv)
{
	data->parse.fd = -1;
	if (argc != 2)
		exit_cubed(data, -1, INVALID_NUMBER_ARGS, 0);
	if (WIDTH > MAXWIDTH || WIDTH < MINWIDTH || \
	HEIGHT < MINHEIGHT || HEIGHT > MAXHEIGHT)
		exit_cubed(data, -1, "Config error: Windows size out of bound", 0);
	extension_checker(data, argv[1], CONFIG_FILE_EXTENSION);
	data->parse.fd = open(argv[1], O_RDWR);
	if (data->parse.fd < 0)
		exit_cubed(data, -1, argv[1], strerror(errno));
	copy_file_to_tab(data, &data->parse);
	process_file_config(data);
}
