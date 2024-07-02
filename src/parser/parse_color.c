/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:12:25 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 23:58:36 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

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

int	get_number(char **line, int *color)
{
	if (!ft_isdigit(**line))
		return (-1);
	while (ft_isdigit(**line))
	{
		*color += **line + '0';
		(*line) ++;
		if (*color > 255)
			return (-1);
	}
	return (0);
}

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

int	set_map_color(t_cube *data, char **args, char *line)
{
	t_v3	color;

	if ((!ft_strcmp(args[0], FLOOR_ID) && data->elements.floor_color.x != -1) || \
		(!ft_strcmp(args[0], CEILING_ID) && data->elements.ceiling_color.x != -1))
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
		data->elements.floor_color = color;
	else if (!ft_strcmp(args[0], CEILING_ID))
		data->elements.ceiling_color = color;
	ft_arr_free(args);
	return (0);
}
