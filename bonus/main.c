/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:00:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/16 17:46:15 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		handle_errors(game, MLX_INIT, NULL);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "cub3d");
	if (!game->win)
		handle_errors(game, MLX_INIT, NULL);
	game->img.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
}

int	main(int ac, char **av)
{
	t_game	game;

	play_sound(&game);
	ft_memset(&game, 0, sizeof (t_game));
	ft_mlx_init(&game);
	parsing(&game, ac, av);
	initialization(&game);
	mlx_hook(game.win, 3, 0, key_release, (void *)&game);
	mlx_hook(game.win, 2, 0, key_press, (void *)&game);
	mlx_hook(game.win, 6, 0, mouse_move, &game);
	mlx_loop_hook(game.mlx, display, &game);
	mlx_hook(game.win, 17, 0, ft_destroy_all, &game);
	mlx_loop(game.mlx);
}
