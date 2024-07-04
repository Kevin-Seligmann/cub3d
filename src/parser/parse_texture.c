/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:11:06 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 22:52:01 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

// Removes the line skip, if a texture has already been found, returns error, or if the
// extension is wrong, or if minilib fails to open the texture
int	get_texture(t_cube *data, char **args, mlx_texture_t **texture)
{
	char	*ls;

	ls = ft_strchr(args[1], '\n');
	if (ls)
		*ls = 0;
	else
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	if ((!ft_strcmp(args[0], EAST_ID) && data->ged.textures.east_wall) || \
		(!ft_strcmp(args[0], WEST_ID) && data->ged.textures.west_wall) || \
		(!ft_strcmp(args[0], NORTH_ID) && data->ged.textures.north_wall) || \
		(!ft_strcmp(args[0], SOUTH_ID) && data->ged.textures.south_wall) || \
		(ft_arr_count_arguments(args) != 2))
		return (print_error(-1, WRONG_LINE_CONTENT, 0));
	if (check_file_extension(args[1], ".png") == -1)
		return (print_error(-1, WRONG_EXTENSION, "Texture file"));
	*texture = mlx_load_png(args[1]);
	if (!*texture)
		return (print_error(-1, CANT_LOAD_TEXTURE, ft_itoa(mlx_errno)));
	ft_printf("[Debug] Loaded: %s\n", args[1]); // Debug
	return (0);
}

// Gets the texture and sets its value on the data struct
int	set_texture(t_cube *data, char **args)
{
	mlx_texture_t	*texture;

	if (get_texture(data, args, &texture) == -1)
	{
		ft_arr_free(args);
		return (-1);
	}
	if (!ft_strcmp(args[0], EAST_ID))
		data->ged.textures.east_wall = texture;
	else if (!ft_strcmp(args[0], WEST_ID))
		data->ged.textures.west_wall = texture;
	else if (!ft_strcmp(args[0], NORTH_ID))
		data->ged.textures.north_wall = texture;
	else if (!ft_strcmp(args[0], SOUTH_ID))
		data->ged.textures.south_wall = texture;
	ft_arr_free(args);
	return (0);
}
