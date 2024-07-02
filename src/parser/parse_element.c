/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:26:33 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/03 00:24:42 by kseligma         ###   ########.fr       */
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
	if (!args[0] || !ft_strcmp(args[0], "\n")) // This makes a line full of spaces equal to a line skip (Prob should change)
	{
		ft_arr_free(args);
		return (0);
	}
	if (!ft_strcmp(args[0], EAST_ID) || \
		!ft_strcmp(args[0], WEST_ID) || \
		!ft_strcmp(args[0], NORTH_ID) || \
		!ft_strcmp(args[0], SOUTH_ID))
		return (set_texture(data, args));
	if (!ft_strcmp(args[0], FLOOR_ID) || \
		!ft_strcmp(args[0], CEILING_ID))
		return (set_map_color(data, args, line));
	ft_arr_free(args);
//	printf("%s Line\n", line);
	return (print_error(-1, WRONG_LINE_CONTENT, 0));
}
