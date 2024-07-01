/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:15:08 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/30 23:07:01 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

int	open_file(char *path, int *fd)
{
	*fd = open(path, O_RDWR); //Write mode so it doesn't open directories
	if (*fd == -1)
		return (print_error(-1, path, strerror(errno)));
	return (0);
}

t_bool	read_next_line(int fd, char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	*buffer = get_next_line(fd);
	if (!*buffer)
		return (FALSE);
	return (TRUE);
}

t_bool	obligatory_elements_are_set(t_cube *data)
{
	if (data->files.east_texture == 0 || \
		data->files.north_texture == 0 || \
		data->files.south_texture == 0 || \
		data->files.west_texture == 0 || \
		data->elements.ceiling_color.x == -1 || \
		data->elements.floor_color.x == -1 || \
		data->elements.ceiling_color.y == -1 || \
		data->elements.floor_color.y == -1 || \
		data->elements.ceiling_color.z == -1 || \
		data->elements.floor_color.z == -1)
		return (FALSE);
	return (TRUE);
}

void	set_default_config(t_cube *data)
{
	data->files.east_texture = 0;
	data->files.north_texture = 0;
	data->files.south_texture = 0;
	data->files.west_texture = 0;
	data->elements.ceiling_color.x = -1;
	data->elements.floor_color.x = -1;
	data->elements.ceiling_color.y = -1;
	data->elements.floor_color.y = -1;
	data->elements.ceiling_color.z = -1;
	data->elements.floor_color.z = -1;
}
