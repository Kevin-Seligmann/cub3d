/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:12:25 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:24:05 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Gets an 32 bits integer from r, g, b, a values.
*/
unsigned int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/*
	Skips spaces and commas.
*/
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

/*
	Extracts a number from 0 to 255.
*/
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

/*
	Parses the line through numbers, comas and spaces to get
	the colors.
*/
int	get_color(t_rgba *color, char *line, char *identifier)
{
	while (*line == ' ')
		line ++;
	line += ft_strlen(identifier);
	line ++;
	while (*line == ' ')
		line ++;
	if (get_number(&line, &color->r) == -1)
		return (-1);
	if (skip_coma(&line) == -1)
		return (-1);
	if (get_number(&line, &color->g) == -1)
		return (-1);
	if (skip_coma(&line) == -1)
		return (-1);
	if (get_number(&line, &color->b) == -1)
		return (-1);
	while (*line == ' ')
		line ++;
	if (*line)
		return (-1);
	color->a = 0xff;
	return (0);
}

/*
	Checks if the color has been set before.
	If not, extracts the color from the line.
	If there's an error returns -1.
*/
int	get_map_color(t_cube *data, char **args, char *line)
{
	t_rgba	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	color.a = 0;
	if ((!ft_strcmp(args[0], CEILING_ID) && data->sim.ceiling_color != 0) || \
	(!ft_strcmp(args[0], FLOOR_ID) && data->sim.floor_color != 0))
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	if (get_color(&color, line, args[0]) == -1)
		return (print_error(-1, WRONG_LINE_CONTENT, "Color"));
	if (!ft_strcmp(args[0], FLOOR_ID))
		data->sim.floor_color = get_rgba(color.r, color.g, color.b, color.a);
	else if (!ft_strcmp(args[0], CEILING_ID))
		data->sim.ceiling_color = get_rgba(color.r, color.g, color.b, color.a);
	return (0);
}
