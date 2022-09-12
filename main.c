/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:00:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 17:52:38 by hakermad         ###   ########.fr       */
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
	display(&game);
	mlx_loop(game.mlx);
}
