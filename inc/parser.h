/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/28 16:52:54 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cubed_data_structures.h"

int		check_file_extension(char *map_f, char *extension);
int		open_file(char *path, int *fd);
int		parser(t_cube *data, int argc, char **argv);
t_bool	read_next_line(int fd, char **buffer);
t_bool	obligatory_elements_are_set(t_cube *data);
void	set_default_config(t_cube *data);
int		parse_element(t_cube *data, char *line);
t_bool	is_map_line(char *line);
int		set_texture(t_cube *data, char **args);
int		set_map_color(t_cube *data, char **args, char *line);
int		parse_map(t_cube *data, char *line);
t_bool	is_map_valid(t_map *map, int **arr);

#endif
