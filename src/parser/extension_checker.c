/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:28:15 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 13:28:21 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
#include "parser.h"

int	extension_checker(char *file, char *extension)
{
	size_t	extension_length;
	size_t	file_length;

	extension_length = ft_strlen(extension);
	file_length = ft_strlen(file);
	if (extension_length > file_length)
		return (print_error(-1, WRONG_EXTENSION, file));
	while (extension_length > 0)
	{
		if (extension[extension_length] != file[file_length])
			return (print_error(-1, WRONG_EXTENSION, file));
		extension_length --;
		file_length --;
	}
	return (0);
}
