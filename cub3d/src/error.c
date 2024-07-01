/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:53:44 by kseligma          #+#    #+#             */
/*   Updated: 2024/06/30 21:53:59 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	print_error(int return_value, char *error_message, char *strerror)
{
	write(2, ERROR_STANDARD_MESSAGE, ft_strlen(ERROR_STANDARD_MESSAGE));
	write(2, PROGRAM_NAME, ft_strlen(PROGRAM_NAME));
	write(2, ERROR_SEPARATOR, ft_strlen(ERROR_SEPARATOR));
	write(2, error_message, ft_strlen(error_message));
	if (strerror)
	{
		write(2, ERROR_SEPARATOR, ft_strlen(ERROR_SEPARATOR));
		write(2, strerror, ft_strlen(strerror));
	}
	write(2, "\n", 2);
	return (return_value);
}
