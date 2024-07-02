/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 17:37:19 by kseligma         ###   ########.fr       */
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
	xpm_t *east_wall;
	xpm_t *north_wall;
	xpm_t *south_wall;
	xpm_t *west_wall;
}	t_texture_pack;

// This contains MLX (Graphic Engine) Data (GED)
typedef struct s_ged
{
	void	*mlx;
	void	*win;
	t_texture_pack	textures;
	int		width;
	int		height;
	int		closeflag;
}	t_ged;

// A list of file descriptor, for textures and config file
typedef struct s_fds
{
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
	t_ged	ged;
	t_fds	files;
	t_elem	elements;
}	t_cube;

#endif
