/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/10/07 22:29:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites(t_game *game, char *path, t_img *sprite)
{
	int		width;

	sprite->img = mlx_xpm_file_to_image(game->mlx, path, &width, &sprite->len);
	if (!(sprite->img))
		handle_errors(game, SPRITE_ERR, path);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_length, &sprite->endian);
}

void	init_color(t_img *img, int num_color, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H / 2)
		{
			if (c == 'F')
				ft_mlx_pixel_put(img, i, j + (WIN_H / 2), num_color);
			else
				ft_mlx_pixel_put(img, i, j, num_color);
			j++;
		}
		i++;
	}
}

void	init_color_sprite(t_game *game)
{
	init_color(&game->img, game->color_floor, 'F');
	init_color(&game->img, game->color_roof, 'C');
	init_sprites(game, game->sprite.n_path, &game->sprite.north);
	init_sprites(game, game->sprite.s_path, &game->sprite.south);
	init_sprites(game, game->sprite.e_path, &game->sprite.east);
	init_sprites(game, game->sprite.w_path, &game->sprite.west);
}
