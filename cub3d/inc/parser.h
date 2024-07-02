/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 08:12:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		ft_format_cub(char *map_f);
int		open_file(char *path, int *fd);
int		parser(t_cube *data, int argc, char **argv);
t_bool	read_next_line(int fd, char **buffer);
t_bool	obligatory_elements_are_set(t_cube *data);
void	set_default_config(t_cube *data);

#endif
