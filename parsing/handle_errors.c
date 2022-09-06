/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:15:48 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 12:19:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	handle_errors(int error, char *str)
{
	if (error == NB_ARGUMENTS)
		write(2, "Wrong number of arguments.\n", 27);
	else if (error == WRONG_NAME)
	{
		write (2, "Error\nWrong file name : ", 24);
		write (2, str, ft_strlen(str));
		write (2, "\n", 1);
	}
	else if (error == UNEXIST_MAP)
		write(2, "This map does not exit. Change it now.\n", 39);
	exit (EXIT_FAILURE);
}