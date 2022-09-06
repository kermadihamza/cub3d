/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:00:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 16:42:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_errors(MLX_INIT, NULL);
	game->win = mlx_new_window(game->mlx, 1024, 1024, "cub3d");
	if (!game->win)
	{
		free (game->mlx);
		handle_errors(MLX_INIT, NULL);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	parsing(&game, ac, av);
	ft_mlx_init(&game);
	// mlx_key_hook(game.win, ft_key_hook, &game);
	// mlx_hook(game.win, 17, 0, ft_destroy_all, &game);
	mlx_loop(game.mlx);
}
