/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_data_structures.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:33:13 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 11:34:15 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_DATA_STRUCTURES_H

# define CUBED_DATA_STRUCTURES_H

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
