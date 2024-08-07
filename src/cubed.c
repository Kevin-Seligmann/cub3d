/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:41:35 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/07 13:34:54 by kseligma         ###   ########.fr       */
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
	update_size(&data->ged);
	do_rotation(&data->sim.player, data->ged.key_flag);
	do_translation(&data->sim.player, data->sim.map, data->ged.key_flag);
	update_doors(data, data->sim.map);
	ft_raycasting(data);
}

/*
	MLX init and hooks.
*/
static int	config_mlx(t_cube *data)
{
	data->ged.key_flag = 0;
	data->ged.win_height = HEIGHT;
	data->ged.win_width = WIDTH;
	data->ged.mlx = mlx_init(WIDTH, HEIGHT, WINDOWS_TITLE, true);
	if (!data->ged.mlx)
		return (print_error(-1, MLX_ERROR, mlx_strerror(mlx_errno)));
	data->ged.img = mlx_new_image(data->ged.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->ged.mlx, data->ged.img, 0, 0);
	mlx_key_hook(data->ged.mlx, key_hook, data);
	mlx_loop_hook(data->ged.mlx, simulation_loop, data);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_cube	data;

	if (parser(&data, argc, argv) == -1)
		return (EXIT_FAILURE);
	if (config_mlx(&data) == -1)
		return (EXIT_FAILURE);
	mlx_loop(data.ged.mlx);
	mlx_terminate(data.ged.mlx);
	ft_arr_free_int(data.sim.map);
	return (EXIT_SUCCESS);
}
