/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseligma <kseligma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:53:44 by kseligma          #+#    #+#             */
/*   Updated: 2024/07/30 12:19:57 by kseligma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

#define PR_BUFFSIZE 1000

/*
	Function that returns values and print error messages on one line, 
	to shorten the lines that takes to return from a failed function
	from 4 to 1 (Norminette + braces)
*/
int	print_error(int return_value, \
const char	*error_message, const char *strerror)
{
	char	buffer[PR_BUFFSIZE + 1];

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
