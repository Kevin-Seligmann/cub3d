/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/07 13:34:17 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
	Config file:
		The config file starts with elements, then a map.
		The overall format of an 'element' is 'IDENTIFIER     VALUES'.
		Incorrect values or identifiers results in error.
		There can be as many spaces as desired in an element.
		Ceiling and floor color values are a RBG tuple separated by commas.
		Textures values are a file path.
		A door must have one texture for the door, then another for the side.
		Sprites value are a texture. Up to 30 textures for each sprite
			might be provided, on separated lines.
		A sprite that has no map value is not an error, a sprite
			on the map that has no texture will not be displayed.
		The map starts when a map-line is found, there can be
			no elements after.
		A line with spaces is considered a map line.
		Empty lines are ignored.
	Textures and sprites:
		A wall texture is displayed according to which side the wall
			is facing, so 4 textures at least must be provided.
		.png and .xmp42 supported.
	Map:
		Limits:
			A '1' represents a wall.
			A '0' represents an open space.
			An ' ' representes nothing.
			All non-walls except spaces must be enclosed by walls.
		Player:
			'EANS' represents a player and its direction.
		Door:
			'OP' represents a north-south or east-west wall.
			A door must be sorrounded by walls to its side.
		Sprites:
		'	'98765432' represent sprites.
*/

# include "cubed_data_structures.h"

/* Process file config */
int		process_file_config(t_cube *data);

/* Checks if the file has the extension provided */
int		extension_checker(char *file, char *extension);

/* Parses a configuration file */
int		parser(t_cube *data, int argc, char **argv);

/* Checks if a line on the config file belongs to the map */
bool	is_map_line(char *line);

/* Gets a texture from config file to mlx struct */
int		get_texture(t_cube *data, char **args);

/* Parses ceiling/roof color */
int		get_map_color(t_cube *data, char **args, char *line);

/* Process map */
int		process_map(t_cube *data, int ind);
int		get_map_info(t_parser *parse, t_sim *sim, int **arr);

/* If windows size change, update images */
void	update_size(t_ged *ged);

#endif
