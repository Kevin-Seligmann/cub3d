#include "cubed.h"
#include "parser.h"

// Funcion que libera la memoria de la estructura del mapa
void	ft_free_map(t_map *map)
{
	int	ind;

	ind = 0;
	if (!map->map)
		return ;
	while (map->map[ind])
	{
		free(map->map[ind]);
		ind ++;
	}
	free(map->map);
	map->map = 0;
}
