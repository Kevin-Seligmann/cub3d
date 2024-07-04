/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 18:10:36 by kseligma         ###   ########.fr       */
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

/*Data related to the mlx_key_hook function
typedef struct mlx_key_data_s
{
	keys_t		key;
	action_t	action;
	int32_t		os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t;
*/
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
	/*void			*win;
	void			*context;
	int				width;
	int				height;
	double			delta_time;*/
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
	int		height;
	int		width;
	t_vf2	player_position;
	t_vf2	player_direction;
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
