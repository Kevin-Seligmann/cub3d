/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 19:51:04 by kseligma         ###   ########.fr       */
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

/* Red, green, blue, alpha (opacity) */
typedef struct s_rgba
{
	int	r;
	int	g;
	int	b;
	int a;
}	t_rgba;

/* 2D Vector, int. */
typedef struct s_v2
{
	int	x;
	int	z;
}	t_v2;

/* 2D Vector, double. */
typedef struct s_vd2
{
	double	x;
	double	z;
}	t_vd2;

/*
	DDA variables.

	'side'. If a NS or AD wall has been hit.
	'line_'. Which section of a vertial stripe belongs to a texture.
	'wall_dist'. Distance from player to the wall it's moving.
	'texture_x'. X coordinate on texture. (0, 1).
	'camera_x'. X coordinate on camera. (-1, 1).
	'step'. Pair of -1 or 1, coordinate change based on direction.
	'pos_int'. Position on the map, floored.
	'ray_dir'. Ray direction.
	'side_dist'. Total change of position for DDA iteration.
	'delta_dist'. Change of position for DDA iteration.
	'cam_vect'. Camera vector.
*/
typedef struct s_dda
{
	int				side;
	int				line_start;
	int				line_end;
	unsigned int	line_height;
	double			wall_dist;
	double			texture_x;
	double			camera_x;
	t_v2			step;
	t_v2			pos_int;
	t_vd2			ray_dir;
	t_vd2			side_dist;
	t_vd2			delta_dist;
	t_vd2	cam_vect;
} t_dda;

/*
	Player data.

	'pos'. Player position.
	'dir'. Player direction.
	'old_pos' Player position in previous iteration.
*/
typedef struct s_player
{
	t_vd2	pos;
	t_vd2	dir;
	t_vd2	old_pos;
} t_player;

/*
	Simulation data.

	'map'. Map.
	'height'. Map height.
	'width'. Map width.
	'floor_color'. Floor color.
	'ceiling_color'. Ceiling color'
	'player'. Player data.
*/
typedef struct s_sim
{
	int				**map;
	unsigned int	height;
	unsigned int	width;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_player		player;
}	t_sim;

/*
	Textures.

	the xmp_t will be used only if the texture provided is XMP42.
	xmp_t constains a texture itself. The xpm_t is here to
	keep the reference for no purpose, XML should handle it.
*/
typedef struct s_texture_pack
{
	mlx_texture_t	*east_wall;
	mlx_texture_t	*north_wall;
	mlx_texture_t	*south_wall;
	mlx_texture_t	*west_wall;
	xpm_t			*east_wall_xpm;
	xpm_t			*north_wall_xpm;
	xpm_t			*south_wall_xpm;
	xpm_t			*west_wall_xpm;
}	t_texture_pack;

/*
	Graphic engine (MLX related) data.

	'mlx'. MLX instance.
	'img'. MLX image.
	'textures'. Loaded game textures.
	'key_flag'. Which keys are being pressed.
*/
typedef struct s_ged
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_texture_pack	textures;
	unsigned int	key_flag;
}	t_ged;


/*
	Parser data.

	'fd'. File descriptor.
	'config'. Configuration on a string.
	'conflig_line'. Configuration separated by lines.
*/
typedef struct s_parser
{
	int		fd;
	char	*config;
	char	**config_lines;
}	t_parser;

/*
	Program data. 

	'ged'. Containts data related to minilib and graphics management.
	'parse'. Contains data related to the parsir, only used for parsing.
	'sim'. Map and player data.
	'dda'. DDA Algorithm data for raycasting. 
*/
typedef struct s_cube
{
	t_parser	parse;
	t_ged		ged;
	t_sim		sim;
	t_dda		dda;
}	t_cube;

#endif
