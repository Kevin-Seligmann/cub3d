/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:19:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 15:43:33 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H

# define CUBED_H

/* System libraries */
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

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

/* Floor color  identifier */
# define FLOOR_ID "F"

/* Ceiling color identifier */
# define CEILING_ID "C"

/* Program constants */
# define todo
/*
	To do:
	They dont look like cubes for all WIDTH and HEIGHT values.	
*/
/* Windows Width */
# define WIDTH 800.

/* Windows Height */
# define HEIGHT 600.

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
# define ROTSPEED 0.1

/* Values for keypress flags, helps making movement smoother */
# define CUBK_A 0x1
# define CUBK_S 0x2
# define CUBK_D 0x4
# define CUBK_W 0x8
# define CUBK_L 0x10
# define CUBK_R 0x20

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

/* Prints an error with the provided strings and returns 'return_value' */
int				print_error(int return_value, \
const char		*error_message, const char *strerror);

/* MLX initialization, hooks, and termination */
int				config_mlx(t_cube *data);

/* Hook for MLX that contains an actions for each key press */
void			key_hook(mlx_key_data_t keydata, void *param);

/* Performs the translation calculations */
void			do_translation(int key, void *param);

/* Performs the rotation calculations */
void			do_rotation(int key, void *param);

/* DDA algorithm, hooked into mlx_loop, executed each frame */
void			simulation_loop(void *data);

/* Stores in dst the clockwise perpendicular 2d´vector to src */
void			perp_clockwise_v2(t_v2 *src, t_v2 *dst);
void			perp_clockwise_vf2(t_vd2 *src, t_vd2 *dst);

/* Transforms RGBA into a 4 bytes hex */
unsigned int	get_rgba(int r, int g, int b, int a);

/* Draws the scene */
void			draw(t_sim *map, t_ged *gph, t_color *colors, int x);

/* Performs the raycasting algorithm, DDA */
void			ft_raycasting(t_cube *game);

#endif
