/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:37:59 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/20 18:32:54 by oseivane         ###   ########.fr       */
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

void	on_off_minimap(mlx_key_data_t keydata, t_cube *data)
{
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		if (data->ged.minimap->enabled == 1)
			data->ged.minimap->enabled = 0;
		else if (data->ged.minimap->enabled == 0)
			data->ged.minimap->enabled = 1;
	}
}
