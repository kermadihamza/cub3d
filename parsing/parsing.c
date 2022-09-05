/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:05:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/05 17:20:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		handle_errors(NB_ARGUMENTS, NULL);
	init_map(game, av);
}
