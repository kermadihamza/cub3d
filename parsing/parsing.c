/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:19:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/13 21:02:14 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		handle_errors(NB_ARGUMENTS, NULL);
	check_error_name(av[1]);
	read_map(game, av[1]);
	error_map(game->map);
	parsing_rgb(game->floor, &game->color_floor);
	parsing_rgb(game->roof, &game->color_roof);
	init_color_sprite(game);
	init_player_pos(game);
}
