/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:29:53 by kseligma          #+#    #+#             */
/*   Updated: 2024/08/19 21:30:02 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	delete_texture(mlx_texture_t **text)
{
	if (*text)
	{
		mlx_delete_texture(*text);
		*text = NULL;
	}
}

static void	destroy_textures(t_texture_pack *texts)
{
	int	ind1;
	int	ind2;

	delete_texture(&texts->door);
	delete_texture(&texts->door_side);
	delete_texture(&texts->east_wall);
	delete_texture(&texts->north_wall);
	delete_texture(&texts->south_wall);
	delete_texture(&texts->west_wall);
	ind1 = 0;
	while (ind1 < 8)
	{
		ind2 = 0;
		while (ind2 < 30)
		{
			delete_texture(&texts->sprites_text[ind1][ind2]);
			ind2++;
		}
		ind1++;
	}
}

void	exit_cubed(t_cube *data, int exit_code, char *err, const char *strerr)
{
	if (data->parse.config_lines)
		ft_arr_free(data->parse.config_lines);
	if (data->parse.fd > -1)
		close(data->parse.fd);
	if (data->parse.config)
		free(data->parse.config);
	if (data->sim.map)
		ft_arr_free_int(data->sim.map);
	destroy_textures(&data->ged.textures);
	if (data->ged.mlx)
		mlx_terminate(data->ged.mlx);
	if (exit_code == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	exit (print_error(EXIT_FAILURE, err, strerr));
}

#define PR_BUFFSIZE 3000

/*
	Function that returns values and print error messages on one line, 
	to shorten the lines that takes to return from a failed function
	from 4 to 1 (Norminette + braces)
*/
int	print_error(int return_value, \
const char	*error_message, const char *strerror)
{
	char	buffer[PR_BUFFSIZE + 1];

	if (!error_message)
		return (return_value);
	buffer[0] = 0;
	ft_strlcat(buffer, ERROR_STANDARD_MESSAGE, PR_BUFFSIZE);
	ft_strlcat(buffer, PROGRAM_NAME, PR_BUFFSIZE);
	ft_strlcat(buffer, ERROR_SEPARATOR, PR_BUFFSIZE);
	ft_strlcat(buffer, error_message, PR_BUFFSIZE);
	if (strerror)
	{
		ft_strlcat(buffer, ERROR_SEPARATOR, PR_BUFFSIZE);
		ft_strlcat(buffer, strerror, PR_BUFFSIZE);
	}
	ft_strlcat(buffer, "\n", PR_BUFFSIZE);
	write(STDERR_FILENO, buffer, ft_strlen(buffer));
	return (return_value);
}
