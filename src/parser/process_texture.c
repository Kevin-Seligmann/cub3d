/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:11:06 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/04 20:14:33 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Gets the texture from minilib.
*/
static int	get_wall_texture(t_ged *ged, char **args, \
mlx_texture_t **texture, xpm_t **xpm)
{
	if ((!ft_strcmp(args[0], EAST_ID) && ged->textures.east_wall) || \
		(!ft_strcmp(args[0], WEST_ID) && ged->textures.west_wall) || \
		(!ft_strcmp(args[0], NORTH_ID) && ged->textures.north_wall) || \
		(!ft_strcmp(args[0], SOUTH_ID) && ged->textures.south_wall) || \
		(ft_arr_count_arguments(args) != 2))
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	if (extension_checker(args[1], ".png") != -1)
		*texture = mlx_load_png(args[1]);
	else if ((extension_checker(args[1], ".xpm42") != -1))
	{
		*xpm = mlx_load_xpm42(args[1]);
		*texture = NULL;
	}
	else
		return (print_error(-1, WRONG_EXTENSION, args[1]));
	if (!*texture)
		return (print_error(-1, CANT_LOAD_TEXTURE, mlx_strerror(mlx_errno)));
	return (0);
}
/*
	Gets the texture of a wall.
*/
static int	save_wall_texture(t_ged *ged, char **args)
{
	mlx_texture_t	*texture;
	xpm_t			*xpm;

	if (get_wall_texture(ged, args, &texture, &xpm) == -1)
		return (-1);
	if (!ft_strcmp(args[0], EAST_ID))
		ged->textures.east_wall = texture;
	else if (!ft_strcmp(args[0], WEST_ID))
		ged->textures.west_wall = texture;
	else if (!ft_strcmp(args[0], NORTH_ID))
		ged->textures.north_wall = texture;
	else if (!ft_strcmp(args[0], SOUTH_ID))
		ged->textures.south_wall = texture;
	if (!ft_strcmp(args[0], EAST_ID))
		ged->textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], WEST_ID))
		ged->textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], NORTH_ID))
		ged->textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], SOUTH_ID))
		ged->textures.east_wall_xpm = xpm;
	return (0);
}

/*
	Gets door texture.
*/
static int	save_door_texture(t_ged *ged, char **args)
{
	if (ged->textures.door != 0 || ft_arr_count_arguments(args) != 3)
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	if (extension_checker(args[1], ".png") != -1)
		ged->textures.door = mlx_load_png(args[1]);
	else if ((extension_checker(args[1], ".xpm42") != -1))
	{
		ged->textures.door_xpm = mlx_load_xpm42(args[1]);
		if (ged->textures.door_xpm != NULL)
			*ged->textures.door = ged->textures.door_xpm->texture;	
	}
	else
		return (print_error(-1, WRONG_EXTENSION, args[1]));
	if (extension_checker(args[2], ".png") != -1)
		ged->textures.door_side = mlx_load_png(args[2]);
	else if ((extension_checker(args[2], ".xpm42") != -1))
	{
		ged->textures.door_side_xpm = mlx_load_xpm42(args[2]);
		if (ged->textures.door_side_xpm != NULL)
			*ged->textures.door_side = ged->textures.door_side_xpm->texture;
	}
	else
		return (print_error(-1, WRONG_EXTENSION, args[1]));
	if (!ged->textures.door_side || !ged->textures.door)
		return (print_error(-1, CANT_LOAD_TEXTURE, mlx_strerror(mlx_errno)));
	return (0);
}

/*
	Gets and stores textures. Detecs minilib errors parsing it,
	wrong extensions. Supports xpm42 and png.
*/
int get_texture(t_cube *data, char **args)
{
	if (!ft_strcmp(args[0], DOOR_ID))
		return (save_door_texture(&data->ged, args));
	else
		return (save_wall_texture(&data->ged, args));
}
