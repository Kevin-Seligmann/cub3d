/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:12:25 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/28 12:26:40 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

unsigned int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Skips the comas in the string
int	skip_coma(char **line)
{
	while (**line == ' ')
		(*line) ++;
	if (**line != ',')
		return (-1);
	(*line) ++;
	while (**line == ' ')
		(*line) ++;
	return (0);
}

// Gets color number, if bigger than 255 or returns error
int	get_number(char **line, int *color)
{
	if (!ft_isdigit(**line))
		return (-1);
	while (ft_isdigit(**line))
	{
		*color = (*color) * 10 + **line - '0';
		(*line) ++;
		if (*color > 255)
			return (-1);
	}
	return (0);
}

// Loop through the line with the color, skipping commas and getting the colors
int	get_color(t_v3 *color, char *line, char *identifier)
{
	while (*line == ' ')
		line ++;
	line += ft_strlen(identifier);
	line ++;
	while (*line == ' ')
		line ++;
	if (get_number(&line, &color->x) == -1)
		return (-1);
	if (skip_coma(&line) == -1)
		return (-1);
	if (get_number(&line, &color->y) == -1)
		return (-1);
	if (skip_coma(&line) == -1)
		return (-1);
	if (get_number(&line, &color->z) == -1)
		return (-1);
	while (*line == ' ')
		line ++;
	if (*line != '\n')
		return (-1);
	return (0);
}

// Set the map color
int	set_map_color(t_cube *data, char **args, char *line)
{
	t_v3	color;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	if ((!ft_strcmp(args[0], FLOOR_ID) && data->colors.floor_color.x != -1) || \
		(!ft_strcmp(args[0], CEILING_ID) && data->colors.ceiling_color.x != -1)) // If the information is repeated
	{
		ft_arr_free(args);
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	}
	if (get_color(&color, line, args[0]) == -1)
	{
		ft_arr_free(args);
		return (print_error(-1, WRONG_LINE_CONTENT, "Color"));
	}
	if (!ft_strcmp(args[0], FLOOR_ID))
		data->colors.floor_color = color;
	else if (!ft_strcmp(args[0], CEILING_ID))
		data->colors.ceiling_color = color;
	ft_arr_free(args);
	return (0);
}
