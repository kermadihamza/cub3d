/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:15:48 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/05 17:20:46 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	handle_errors(int error, void *ptr)
{
	if (error = NB_ARGUMENTS)
		write(2, "Wrong number of arguments.\n", 27);
}