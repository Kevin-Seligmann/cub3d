/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:12 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/30 23:01:59 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

int		open_file(char *path, int *fd);
int		parser(t_cube *data, int argc, char **argv);
t_bool	read_next_line(int fd, char **buffer);
t_bool	obligatory_elements_are_set(t_cube *data);
void	set_default_config(t_cube *data);

#endif
