/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:15:08 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 13:26:15 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

// Uses GNL to return the next line, frees the previous line, returns FALSE on end of file
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
// If a line is the line of the map (Doesn't start with a letter, as that would mean an identifier) returns TRUE
t_bool	is_map_line(char *line) // Every line that doesn't start with an identifier or is empty is a map line
{
	if (*line == '\n')
		return (FALSE);
	while (*line)
	{
		if (ft_isalpha(*line))
			return (FALSE);
		if (ft_strchr("10", *line))
			return (TRUE);
		line ++;
	}
	return (TRUE);
}
