/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/21 16:38:51 by kseligma         ###   ########.fr       */
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
# include "defines.h"

/* Process file config */
void		process_file_config(t_cube *data);

/* Checks if the file has the extension provided */
void		extension_checker(t_cube *data, char *file, char *extension);

/* Parses a configuration file */
void		parser(t_cube *data, int argc, char **argv);

/* Checks if a line on the config file belongs to the map */
bool		is_map_line(char *line);

/* Gets a texture from config file to mlx struct */
int			get_texture(t_cube *data, char **args);

/* Parses ceiling/roof color */
int			get_map_color(t_cube *data, char **args, char *line);

/* Process map */
void		process_map(t_cube *data, int ind);
void		get_map_info(t_cube *data, t_parser *parse, t_sim *sim, int **arr);

/* If an identifier is a sprite */
bool		is_sprite_id(char *id);

/*
	If a sprite has been found on the map, but its texture has not been
	provided
*/
bool		found_sprite_is_not_set(t_cube *data);

/* Gets a sprite texture */
int			get_sprite_texture(t_cube *data, char **args);

/*
	If a piece of map is not a border (an 1), checks that
	is not the limit of the map itself or any of its neighbours
	are spaces. That would entail an open map.
*/
void		check_square_enclosed(t_cube *data, \
t_sim *map, unsigned int i, unsigned int j);

#endif
