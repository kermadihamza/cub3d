/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/10/24 15:48:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
