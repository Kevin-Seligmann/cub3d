/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:15:08 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 18:14:06 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

//Esta funcion checkea el formato del fichero mapa .cub

int	check_file_extension(char *file, char *extension)
{
	size_t	extension_length;
	size_t	file_length;

	extension_length = ft_strlen(extension);
	file_length = ft_strlen(file);
	if (extension_length > file_length) // Should we accept a file named ".cub"?
		return (print_error(-1, WRONG_EXTENSION, file));
	while (extension_length > 0)
	{
		if (extension[extension_length] != file[file_length])
			return (print_error(-1, WRONG_EXTENSION, file));
		extension_length --;
		file_length --;
	}
	return (0);
}

int	open_file(char *path, int *fd)
{
	if (check_file_extension(path, CONFIG_FILE_EXTENSION) == -1)
		return (-1);
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

t_bool	is_map_line(char *line)
{
	while (*line)
	{
		if (*line == '1')
			return (TRUE);
		if (ft_isalnum(*line))
			return (FALSE);
		line ++;
	}
	return (FALSE);
}
