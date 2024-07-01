/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:19:14 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/01 23:10:33 by mac              ###   ########.fr       */
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

// Identifiers
# define NORTH_ID "NO"
# define SOUTH_ID "SO"
# define EAST_ID "EA"
# define WEST_ID "WE"
# define FLOOR_ID "F"
# define CEILING_ID "C"

// Output messages
# define PROGRAM_NAME "cub3D"
# define INVALID_NUMBER_ARGS "The number of arguments is invalid"
# define ERROR_SEPARATOR ": "
# define ERROR_STANDARD_MESSAGE "Error\n"
# define MISSING_CONFIG_DATA "The configuration file is incomplete"
# define MEMORY_ERROR "Memory allocation has failed"

// Functions
int	print_error(int return_value, char *error_message, char *strerror);

// Data structures

// Boolean
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// This contains MLX (Graphic Engine) Data (GED)
typedef struct s_ged
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		closeflag;
}	t_ged;

// A list of file descriptor, for textures and config file
typedef struct s_fds
{
	int	north_texture;
	int	south_texture;
	int	west_texture;
	int	east_texture;
	int	argument_fd;
}	t_fds;

// A vector of tree points, also for colors
typedef struct s_v3
{
	int	x;
	int	y;
	int	z;
}	t_v3;

// Value of elements from the config file
typedef struct s_elem
{
	t_v3	floor_color;
	t_v3	ceiling_color;
}	t_elem;

// Global-like struct for all our data
typedef struct s_cube
{
	t_ged	*ged;
	t_fds	files;
	t_elem	elements;
}	t_cube;

#endif
