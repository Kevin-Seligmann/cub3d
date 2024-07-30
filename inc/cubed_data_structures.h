/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 13:58:24 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_DATA_STRUCTURES_H

# define CUBED_DATA_STRUCTURES_H

# include "MLX42/MLX42.h"

# define todo
/*
	To do:
	Documentate structs
*/

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* Textures facing their correspondent side.
Each texture is a png parsed by MLX */
typedef struct s_texture_pack
{
	mlx_texture_t	*east_wall;
	mlx_texture_t	*north_wall;
	mlx_texture_t	*south_wall;
	mlx_texture_t	*west_wall;
}	t_texture_pack;

/* Parser data */
typedef struct s_parser
{
	int		fd;
	char	*config;
	char	**config_lines;
}	t_parser;

typedef struct s_v3
{
	int	x;
	int	y;
	int	z;
}	t_v3;

typedef struct s_v2
{
	int	x;
	int	z;
}	t_v2;

typedef struct s_vf2
{
	float	x;
	float	z;
}	t_vf2;

typedef struct s_color
{
	t_v3			floor_color;
	t_v3			ceiling_color;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
}	t_color;

typedef struct s_map
{
	int				**map;
	unsigned int	height;
	unsigned int	width;
	unsigned int	line_height;
	unsigned int	key;
	int				line_start;
	int				line_end;
	int				side;
	float			wall_dist;
	float			xhit;
	t_v2			map_pos;
	t_v2			step;
	t_vf2			player_position;
	t_vf2			old_player_position;
	t_vf2			player_direction;
	t_vf2			plane;
	t_vf2			camera;
	t_vf2			ray_dir;
	t_vf2			side_dist;
	t_vf2			delta_dist;
}	t_map;

// This contains MLX (Graphic Engine) Data (GED)
typedef struct s_ged
{
	mlx_t			*mlx;
	t_texture_pack	textures;
	mlx_image_t		*img;
}	t_ged;

// Global-like struct for all our data
typedef struct s_cube
{
	t_ged		ged;
	t_parser	parse_data;
	t_color		colors;
	t_map		map;
}	t_cube;

#endif
