/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:19:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 11:20:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		handle_errors(game, NB_ARGUMENTS, NULL);
	ft_memset(&game->player, 0, sizeof (t_player));
	check_error_name(game, av[1]);
	read_map(game, av[1]);
	game->s_map = ft_split(game->map, '\n');
	error_map(game, game->map);
	parsing_rgb(game, game->floor, &game->color_floor);
	parsing_rgb(game, game->roof, &game->color_roof);
	init_player_pos(game);
	init_evil_pos(game);
	init_door_pos(game);
	init_color_sprite(game);
}
