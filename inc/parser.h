/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 20:07:52 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#define todo
/*
	To do:
	Comment these functions
*/

# include "cubed_data_structures.h"

int		process_file_config(t_cube *data);
int		extension_checker(char *map_f, char *extension);
int		open_file(char *path, int *fd);
int		parser(t_cube *data, int argc, char **argv);
bool	read_next_line(int fd, char **buffer);
bool	is_map_line(char *line);
int		get_texture(t_cube *data, char **args);
int		get_map_color(t_cube *data, char **args, char *line);
int		process_map(t_cube *data, int ind);
int		get_map_info(t_sim *map, int **arr);

#endif
