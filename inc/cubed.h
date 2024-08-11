/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:19:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/11 21:10:06 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H

# define CUBED_H

# define todo
/*
	To do:
	Check all headers.
	Check norminette.

	Improve collision to not get stuck in corners. 
	hint: Sometimes the character gets inside the wall.

	Define how to handle spaces.
	Review config file options.

	MLX Termination.
	Clean exit.

	Make squares for all sizes.
*/

/* System libraries */
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

/* User libraries/headers */
# include "libft.h"
# include "MLX42/MLX42.h"
# include "cubed_data_structures.h"

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
# define WIDTH 800.

/* Windows Height */
# define HEIGHT 600.

/*Minimap scale multiplier*/
# define MM_SCALE 5.

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
	0. Close.
	1-49. Opening.
	50. Open.
	51-99. Closing.
*/
# define DOOR_NS 100
# define DOOR_WE 200

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

/* Prints an error with the provided strings and returns 'return_value' */
int				print_error(int return_value, \
const char		*error_message, const char *strerror);

/* Hook for MLX that contains an actions for each key press */
void			key_hook(mlx_key_data_t keydata, void *param);

/* Performs the translation calculations */
void			do_translation(t_player *player, \
int **map, unsigned int key_flag);

/* Performs the rotation calculations */
void			do_rotation(t_player *player, t_ged *ged, int unsigned key_flag);

/* Stores in dst the clockwise perpendicular 2d´vector to src */
void			perp_clockwise_v2(t_v2 *src, t_v2 *dst);
void			perp_clockwise_vf2(t_vd2 *src, t_vd2 *dst);

/* Transforms RGBA into a 4 bytes hex */
unsigned int	get_rgba(int r, int g, int b, int a);

/* Draws the scene and minimap*/
void			draw(t_dda *dda, t_ged *ged, t_sim *sim);
void			draw_mini_map(t_dda *dda, t_ged *ged, t_sim *sim);
void			draw_mini_player(t_ged *ged, t_sim *sim);
void			draw_square_1(t_ged *ged, unsigned int x, unsigned int y);
void			draw_square_2(t_ged *ged, unsigned int x, unsigned int y);

/* Performs the raycasting algorithm, DDA */
void			ft_raycasting(t_cube *game);

/* Tests if the block hit is the side of a door */
void			check_door_side(t_dda *dda, int **map);

/* If a block is a door, tests if the door has been hit */
void			check_door_hit(t_dda *dda, \
t_player *player, int **map, int *hit);

/* DDA - Detects ray hit */
void			set_raycasting_data(t_player *player, t_dda *dda, t_ged *ged);
void			set_step(t_player *player, t_dda *dda);
void			ft_dda(t_dda *dda, t_player *player, int **map);

/* Checks if a door - open or close - has been it */
void			ft_dda_door(t_dda *dda, int **map);

/* Updates door status each frame*/
void			update_doors(t_cube *data, int **map);

/* Closes the windows to finish the simulation. */
void			escape_window(mlx_key_data_t keydata, t_cube *data);

/*On/Off the map*/
void			on_off_minimap(mlx_key_data_t keydata, t_cube *data);

#endif
