/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:41:35 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/02 07:20:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

#define norm_error "Remove comments before finishing"

int	parser(t_cube *data, int argc, char **argv); // I put it here because it will not be called from anywhere else

// There's a minimalistic structure of the program here, as we progress it will change.
int	main(int argc, char **argv)
{
	static t_cube data;

	if (parser(&data, argc, argv) == -1) // First step is parsing, if any error occurs, exit.
		return (0);
	// Minilib initialization
	ft_go(&data); // This function will  start the game
	return (0);
}
