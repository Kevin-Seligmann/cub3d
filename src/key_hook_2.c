/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:37:59 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 20:22:20 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

/*
	Closes the windows to finish the simulation.
*/
void	escape_window(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->ged.mlx);
}

void	minimap_controls(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		if (data->ged.minimap->enabled == 1)
			data->ged.minimap->enabled = 0;
		else if (data->ged.minimap->enabled == 0)
			data->ged.minimap->enabled = 1;
	}
	else if (keydata.key == MLX_KEY_Z && data->ged.mm_scale < 50)
		data->ged.mm_scale ++;
	else if (keydata.key == MLX_KEY_X && data->ged.mm_scale > 5)
		data->ged.mm_scale --;
	else if (keydata.key == MLX_KEY_C)
		data->ged.mm_scale = MM_SCALE;
}
