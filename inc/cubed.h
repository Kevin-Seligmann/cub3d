/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:19:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/06 12:06:04 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H

# define CUBED_H

// Standard
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

// User libraries
# include "libft.h"
# include "MLX42/MLX42.h"
# include "cubed_data_structures.h"

// Program
# define PROGRAM_NAME "cub3D"
# define CONFIG_FILE_EXTENSION ".cub"

// Identifiers
# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define EAST_ID "EA"
# define WEST_ID "WE"
# define FLOOR_ID "F"
# define CEILING_ID "C"

//Definitions
#define WIDTH 800
#define HEIGHT 600

// Output messages
# define INVALID_NUMBER_ARGS "The number of arguments is invalid"
# define ERROR_SEPARATOR ": "
# define ERROR_STANDARD_MESSAGE "Error\n"
# define MISSING_CONFIG_DATA "The configuration file is incomplete"
# define MEMORY_ERROR "Memory allocation has failed"
# define WRONG_EXTENSION "Filename not supported"
# define WRONG_LINE_CONTENT "The configuration file has an incorrect format"
# define CANT_LOAD_TEXTURE "Couldn't load textures"
# define CANT_LOAD_IMAGE "Couldn't load images"
# define CANT_MAKE_MLX "Couldn't make mlx"
# define NO_MAP_FOUND "Map not found"
# define MAP_NOT_CLOSED "The map is not closed"
# define MANY_PLAYERS "More than one player has been found"

// Functions/Prints
int	print_error(int return_value, char *error_message, char *strerror);

//Functions/free
void	ft_free_map(t_map *map);
int		ft_close(t_cube *map);

//Funcitons/keys
void	my_keyhook(mlx_key_data_t keydata, void* param);

//Fuctions/go
void ft_hook(void* param);
int 	ft_go(t_cube *map);

#endif
