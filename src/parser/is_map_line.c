/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:15:08 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 19:27:33 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

#define todo
/*
	To do:
	Review map requirements on subject.

	A line is a map line if it starts with a serie of spaces
	and then an optional 1.
*/
bool	is_map_line(char *line)
{
	while (*line == ' ')
		line ++;
	if (!*line || *line == '1')
		return (true);
	return (false);
}
