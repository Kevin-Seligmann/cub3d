/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:11:06 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:08:04 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Gets the texture from minilob.
*/
static int	get_texture_struct(t_cube *data, char **args, \
mlx_texture_t **texture, xpm_t **xpm)
{
	if ((!ft_strcmp(args[0], EAST_ID) && data->ged.textures.east_wall) || \
		(!ft_strcmp(args[0], WEST_ID) && data->ged.textures.west_wall) || \
		(!ft_strcmp(args[0], NORTH_ID) && data->ged.textures.north_wall) || \
		(!ft_strcmp(args[0], SOUTH_ID) && data->ged.textures.south_wall) || \
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
	Gets and stores the texture. Detecs minilib errors parsing it,
	wrong extensions. Supports xpm42 and png.
*/
int	get_texture(t_cube *data, char **args)
{
	mlx_texture_t	*texture;
	xpm_t			*xpm;

	xpm = NULL;
	if (get_texture_struct(data, args, &texture, &xpm) == -1)
		return (-1);
	if (!ft_strcmp(args[0], EAST_ID))
		data->ged.textures.east_wall = texture;
	else if (!ft_strcmp(args[0], WEST_ID))
		data->ged.textures.west_wall = texture;
	else if (!ft_strcmp(args[0], NORTH_ID))
		data->ged.textures.north_wall = texture;
	else if (!ft_strcmp(args[0], SOUTH_ID))
		data->ged.textures.south_wall = texture;
	if (!ft_strcmp(args[0], EAST_ID))
		data->ged.textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], WEST_ID))
		data->ged.textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], NORTH_ID))
		data->ged.textures.east_wall_xpm = xpm;
	else if (!ft_strcmp(args[0], SOUTH_ID))
		data->ged.textures.east_wall_xpm = xpm;
	return (0);
}
