/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osg <osg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:41:35 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/04 17:22:41 by osg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

#define norm_error "Remove comments before finishing"

// There's a minimalistic structure of the program here, as we progress it will change.
int	main(int argc, char **argv)
{
	static t_cube data;
	(void)argc;
	(void)argv;

	if (parser(&data, argc, argv) == -1) // First step is parsing, if any error occurs, exit.
		return (0);
	ft_go(&data); // This function will  start the game
	return (0);
}
