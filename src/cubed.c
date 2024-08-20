/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:41:35 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 12:00:49 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

/*
	Main loop hook.
*/
static void	simulation_loop(void *param)
{
	t_cube	*data;

	data = param;
	update_size(data, &data->ged);
	do_rotation(&data->sim.player, &data->ged, data->ged.key_flag);
	do_translation(&data->sim.player, data->sim.map, data->ged.key_flag);
	update_doors(data, data->sim.map);
	draw_mini_map(&data->dda, &data->ged, &data->sim); // Hide map when it's bigger than the screen
	ft_raycasting(data);
	update_sprites(data);
}

/*
	MLX init and hooks.
*/
static void	config_mlx(t_cube *data)
{
	data->ged.key_flag = 0;
	data->ged.win_height = HEIGHT;
	data->ged.win_width = WIDTH;
	data->ged.mlx = mlx_init(WIDTH, HEIGHT, WINDOWS_TITLE, true);
	if (!data->ged.mlx)
		exit_cubed(data, -1, MLX_ERROR, mlx_strerror(mlx_errno));
	data->ged.img = mlx_new_image(data->ged.mlx, WIDTH, HEIGHT);
	data->ged.minimap = mlx_new_image(data->ged.mlx, data->sim.width * MM_SCALE, data->sim.height * MM_SCALE);
	if (!data->ged.img || !data->ged.minimap || \
	mlx_image_to_window(data->ged.mlx, data->ged.minimap, 0, 0) == -1 || \
	mlx_image_to_window(data->ged.mlx, data->ged.img, 0, 0) == -1  || \
	mlx_loop_hook(data->ged.mlx, simulation_loop, data) == false)
		exit_cubed(data, -1, MLX_ERROR, mlx_strerror(mlx_errno));
	mlx_set_instance_depth(data->ged.img->instances, 0);
	mlx_set_instance_depth(data->ged.minimap->instances, 1);
	mlx_get_mouse_pos(data->ged.mlx, &data->ged.mouse_pos.x, &data->ged.mouse_pos.z);
	mlx_key_hook(data->ged.mlx, key_hook, data);
}

int	main(int argc, char **argv)
{
	static t_cube	data;

	parser(&data, argc, argv);
	config_mlx(&data);
	mlx_loop(data.ged.mlx);
	exit_cubed(&data, EXIT_SUCCESS, 0, 0);
	return (EXIT_SUCCESS);
}
