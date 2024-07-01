/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:34:38 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/30 23:30:44 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

int	parse_element(t_cube *data, char *line)
{
	char	**args;

	args = ft_split(line, ' ');
	if (!args)
		return (print_error(-1, MEMORY_ERROR, 0));
	if (ft_strcmp(args[0]), "\n" || !args[0])
	{
		free_arr(args);
		return (0);
	}
	if (ft_strcmp(args[0], EAST_ID))
	else if ft_strcmp(args[0], WEST_ID))
	else if ft_strcmp(args[0], NORTH_ID))
	else if ft_strcmp(args[0], SOUTH_ID))
	else if ft_strcmp(args[0], FLOOR_ID))
	else if ft_strcmp(args[0], CEILING_ID))
	return (0);
}

int	parse_file_config(t_cube *data)
{
	char	*line;

	line = NULL;
	set_default_config(data);
	while (read_next_line(data->files.argument_fd, &line) && is_map_line(line) == FALSE) // Should a line of just spaces be considered empty? Not for now
	{
		if (parse_element(data, line) == -1)
		{
			free(line);
			return (-1);
		}
	}
	if (obligatory_elements_are_set(data) == FALSE)
		return (print_error(-1, MISSING_CONFIG_DATA, 0));
}

int	parser(t_cube *data, int argc, char **argv)
{
	if (argc != 2)
		return (print_error(-1, INVALID_NUMBER_ARGS, 0));
	if (open_file(argv[1], &data->files.argument_fd) == -1)
		return (-1);
	if (parse_file_config(data) == -1)
		return (-1);
	return (0);
}
