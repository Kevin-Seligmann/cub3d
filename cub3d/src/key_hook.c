#include "cubed.h"
#include "parser.h"

int		ft_key_hook(int keycode, t_cube *map)
{
	if (keycode == 53)
		map->ged->closeflag++;
	if (keycode == 13)
		ft_wkey(map);
	if (keycode == 1)
		ft_skey(map);
	if (keycode == 2)
		ft_dkey(map);
	if (keycode == 0)
		ft_akey(map);
	if (map->ged->closeflag > 0)
		ft_close(map);
	mlx_clear_window(map->ged->mlx, map->ged->win);
	//renderizar nuevo mapa
	return (0);
}
