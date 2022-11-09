/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/09 17:18:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites(t_game *game, char *path, t_img *sprite)
{
	int	width;
	int	height;

	sprite->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!(sprite->img) || !height || !width)
		handle_errors(game, SPRITE_ERR, path);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_length, &sprite->endian);
	sprite->width = width;
	sprite->height = height;
}

void	init_color_sprite(t_game *game)
{
	init_sprites(game, game->sprite.north.path, &game->sprite.north);
	init_sprites(game, game->sprite.south.path, &game->sprite.south);
	init_sprites(game, game->sprite.east.path, &game->sprite.east);
	init_sprites(game, game->sprite.west.path, &game->sprite.west);
	init_sprites(game, "./assets/all_sprites.xpm", &game->sprite.all_sprites);
	init_sprites(game, "./assets/numbers.xpm", &game->sprite.numbers);
	init_sprites(game, "./assets/lose.xpm", &game->sprite.lose);
}

void	ft_new_image_blt(t_game *game, t_img *src, t_img *dst, t_pos start)
{
	t_rect	rect;

	dst->img = mlx_new_image(game->mlx, dst->width, dst->height);
	dst->addr = mlx_get_data_addr(dst->img, &dst->bpp,
			&dst->line_length, &dst->endian);
	rect = init_rect(start.x * dst->width, start.y * dst->height,
			dst->width, dst->height);
	bloc_transfer(src, dst, posi(0, 0), rect);
}

void	sprite_blt(t_game *game, t_sprite *sprite, t_img origin)
{
	int	i;

	ft_new_image_blt(game, &origin, &sprite->table, posi(8, 0));
	ft_new_image_blt(game, &origin, &sprite->damage, posi(9, 0));
	i = 0;
	while (i < 10)
	{
		if (i < 3)
			ft_new_image_blt(game, &origin, &game->mess.mess_w[i], posi(i, 4));
		if (i < 4)
		{
			ft_new_image_blt(game, &origin, &sprite->player[i], posi(i, 2));
			ft_new_image_blt(game, &origin, &sprite->door[i], posi(i, 3));
		}
		if (i < 7)
			ft_new_image_blt(game, &origin, &sprite->evil[i], posi(i, 1));
		ft_new_image_blt(game, &sprite->numbers, &sprite->num[i], posi(i, 0));
		i++;
	}
}
