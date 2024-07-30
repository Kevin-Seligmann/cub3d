/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:34:38 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:25:18 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Copies the information stored in the config file to a
	double char array
*/
static int	copy_file_to_tab(t_parser *parse_data)
{
	char	*line;
	char	*aux;

	parse_data->config = ft_calloc(1, sizeof(char *));
	if (!parse_data->config)
		return (print_error(-1, MEMORY_ERROR, 0));
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

	error_value = 0;
	if (argc != 2)
		return (print_error(-1, INVALID_NUMBER_ARGS, 0));
	if (extension_checker(argv[1], CONFIG_FILE_EXTENSION) == -1)
		return (-1);
	data->parse.fd = open(argv[1], O_RDWR);
	if (data->parse.fd == -1)
		return (print_error(-1, argv[1], strerror(errno)));
	error_value = copy_file_to_tab(&data->parse);
	close(data->parse.fd);
	free(data->parse.config);
	if (error_value == -1)
		return (-1);
	error_value = process_file_config(data);
	ft_arr_free(data->parse.config_lines);
	return (error_value);
}
