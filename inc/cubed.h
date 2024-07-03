/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:19:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 16:02:04 by kseligma         ###   ########.fr       */
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
#define WIDTH 1500
#define HEIGHT 1000

// Output messages
# define INVALID_NUMBER_ARGS "The number of arguments is invalid"
# define ERROR_SEPARATOR ": "
# define ERROR_STANDARD_MESSAGE "Error\n"
# define MISSING_CONFIG_DATA "The configuration file is incomplete"
# define MEMORY_ERROR "Memory allocation has failed"
# define WRONG_EXTENSION "Filename not supported"
# define WRONG_LINE_CONTENT "The configuration file has an incorrect format"
# define CANT_LOAD_TEXTURE "Couldn't load textures"

// Functions/Prints
int	print_error(int return_value, char *error_message, char *strerror);

//Functions/free
void	ft_free_map(t_cube *map);
int		ft_close(t_cube *map);

//Funcitons/keys
void	ft_wkey(t_cube *map);
void	ft_skey(t_cube *map);
void	ft_dkey(t_cube *map);
void	ft_akey(t_cube *map);
int		ft_key_hook(int keycode, t_cube *map);

//Fuctions/go
void	ft_go(t_cube *map);

#endif
