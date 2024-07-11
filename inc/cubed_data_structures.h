/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/10 09:28:13 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_DATA_STRUCTURES_H

# define CUBED_DATA_STRUCTURES_H

# include "MLX42/MLX42.h"

// Boolean
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;


typedef struct s_texture_pack
{
	mlx_texture_t *east_wall;
	mlx_texture_t *north_wall;
	mlx_texture_t *south_wall;
	mlx_texture_t *west_wall;
}	t_texture_pack;

// This contains MLX (Graphic Engine) Data (GED)
typedef struct s_ged
{
	t_texture_pack	textures;
}	t_ged;

// A list of file descriptor, for textures and config file
typedef struct s_fds
{
	int		config_file_fd;
	char	*config_file_path;
}	t_fds;

// A vector of tree points, also for colors
typedef struct s_v3
{
	int	x;
	int	y;
	int	z;
}	t_v3;

// A vector of two floats
typedef struct s_vf2
{
	float	x;
	float	z;
}	t_vf2;

// Value of elements from the config file
typedef struct s_elem
{
	t_v3	floor_color;
	t_v3	ceiling_color;
}	t_elem;

typedef struct s_map
{
	int		**map;
	int		mapX;
	int		mapZ;
	int		stepX;
	int		stepZ;
	int		height;
	int		width;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		hit;
	int		side;
	t_vf2	player_position;
	t_vf2	player_direction;
	t_vf2	oldDir;
	t_vf2	plane;
	t_vf2	oldPlane;
	t_vf2	camera;
	t_vf2	rayDir;
	t_vf2	sideDist;
	t_vf2	deltaDist;
	float	time;
	float	oldTime;
	float	frameTime;
	float	moveSpeed;
	float	rotSpeed;
	float	perpWallDist;
	/*const t_v3	red;
	const t_v3	green;
	const t_v3	blue;
	const t_v3	white;
	const t_v3	yellow;*/
	
}	t_map;

// Global-like struct for all our data
typedef struct s_cube
{
	t_ged	ged;
	t_fds	files;
	t_elem	elements;
	t_map	map;
}	t_cube;

#endif
