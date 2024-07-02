/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:26:33 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 14:30:13 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"
/*
int	parse_element(t_cube *data, char *line)
{
	char	**args;

	args = ft_split_charset(line, " \t");
	if (!args)
		return (print_error(-1, MEMORY_ERROR, 0));
	if (!args[0] || ft_strcmp(args[0], "\n")) // This makes a line full of spaces equal to a line skip (Prob should change)
	{
		free_arr(args);
		return (0);
	}
	if (ft_strcmp(args[0], EAST_ID))
		return (set_texture(data, args, EAST_ID));
	else if (ft_strcmp(args[0], WEST_ID))
		return (set_texture(data, args, WEST_ID));
	else if (ft_strcmp(args[0], NORTH_ID))
		return (set_texture(data, args, NORTH_ID));
	else if (ft_strcmp(args[0], SOUTH_ID))
		return (set_texture(data, args, SOUTH_ID));
	else if (ft_strcmp(args[0], FLOOR_ID))
		return (set_map_color(data, args, EAST_ID));
	else if (ft_strcmp(args[0], CEILING_ID))
		return (set_map_color(data, args, EAST_ID));
	free_arr(args);
	return (print_error(-1, WRONG_LINE_CONTENT, 0));
}
*/
