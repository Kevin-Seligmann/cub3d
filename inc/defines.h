/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 02:59:58 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 15:58:40 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H

#define DEFINE_H

/* Program name */
# define PROGRAM_NAME "cub3D"

/* Configuration file defines */
/* Configuration file extension */
# define CONFIG_FILE_EXTENSION ".cub"

/* Wall facing north texture identifier */
# define NORTH_ID "NO"

/* Wall facing south texture identifier */
# define SOUTH_ID "SO"

/* Wall facing east texture identifier */
# define EAST_ID "EA"

/* Wall facing west texture identifier */
# define WEST_ID "WE"

/* Door texture identifier */
# define DOOR_ID "DR"

/* Floor color  identifier */
# define FLOOR_ID "F"

/* Ceiling color identifier */
# define CEILING_ID "C"

/* Sprites identifiers */
# define SPRITE2_ID "S2"
# define SPRITE3_ID "S3"
# define SPRITE4_ID "S4"
# define SPRITE5_ID "S5"
# define SPRITE6_ID "S6"
# define SPRITE7_ID "S7"
# define SPRITE8_ID "S8"
# define SPRITE9_ID "S9"

/* Program constants */
/* Windows Width */
# define MAXWIDTH 4000
# define MINWIDTH 600
# define WIDTH 800.

/* Windows Height */
# define MAXHEIGHT 4000
# define MINHEIGHT 600
# define HEIGHT 600.

/* Max map width */
# define MAX_MAP_WIDTH INT_MAX

/* Max map height */
# define MAX_MAP_HEIGHT INT_MAX

/* Used to determine FOV. For 1, FOV is 90. For 0.66, FOV is 60 */
# define CAM_V_LENGTH 0.66

/* Minimum distance to a wall (Akin to Character size) 
(Put on 0 for evaluation, sometimes it glitches) */
# define MIN_WALL_DIST 0.1

/* Movement speed. A multiplier for the 
magnitude of the movement per translation tick */
/* Having MIN_WALL_DIST + MS >= 1 could cause a crash */
# define MS 0.1

/* Rotation speed. Angle to use in rotation matrix per rotation tick */
/* Having MIN_WALL_DIST + MS >= 1 could cause a crash */
# define ROTMS 0.1

/* Multiplier for mouse rotation movement speed */
# define MOUSE_ROTMS_FACTOR 0.01

/* Values for keypress flags, helps making movement smoother */
# define CUBK_A 0x1
# define CUBK_S 0x2
# define CUBK_D 0x4
# define CUBK_W 0x8
# define CUBK_L 0x10
# define CUBK_R 0x20

/*
	Some elements save their state on the map. Every element that does
	has 100 possible states.
*/

/*
	Door opening state. 
	100 or 200. Closed.
	101-149 or 201 - 249. Opening.
	150 or 250. Opened.
	151-199 or 251-299. Closing.
*/
# define DOOR_NS 100
# define DOOR_WE 200

# define MM_SCALE 10

/* User messages */
# define INVALID_NUMBER_ARGS "The number of arguments is invalid"
# define ERROR_SEPARATOR ": "
# define ERROR_STANDARD_MESSAGE "Error\n"
# define MISSING_CONFIG_DATA "The configuration file is incomplete"
# define MEMORY_ERROR "Memory allocation has failed"
# define WRONG_EXTENSION "Filename not supported"
# define WRONG_LINE_CONTENT "The configuration file has an incorrect format"
# define CANT_LOAD_TEXTURE "Couldn't load textures"
# define CANT_LOAD_IMAGE "Couldn't load images"
# define MLX_ERROR "Minilib error"
# define NO_MAP_FOUND "Map not found"
# define MAP_NOT_CLOSED "The map is not closed"
# define MANY_PLAYERS "More than one player has been found"
# define WINDOWS_TITLE "CUBE3d made by KSeligma & OSeivane"
# define DOOR_NOT_CLOSED "Doors must be placed between two walls"
# define WAR_TEXTURES_FULL "Warning: there's a limit of 30 textures for sprite"
# define MAP_DIMENSIONS_ERROR "Map too big"
# define SPRITE_LIMIT "sprite limit exceded"

#endif
