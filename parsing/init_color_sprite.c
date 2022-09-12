/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/09/12 20:03:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_sprites(t_game *game, char *path, void *ptr)
{
	int		width;
	int		height;

	ptr = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!ptr)
		handle_errors(SPRITE_ERR, path);
}

void	init_color(t_game *game, t_color *color, int num_color)
{
	int	i;
	int	j;

	color->img = mlx_new_image(game->mlx, 1024, 512);
	color->addr = mlx_get_data_addr(color->img, &color->bpp,
			&color->line_length, &color->endian);
	i = 0;
	while (i < 1024)
	{
		j = 0;
		while (j < 512)
		{
			ft_mlx_pixel_put(color, i, j, num_color);
			j++;
		}
		i++;
	}
}

void	init_color_sprite(t_game *game)
{
	init_color(game, &game->color[0], game->color_floor);
	init_color(game, &game->color[1], game->color_roof);
	init_sprites(game, game->north, game->sprite.north);
	init_sprites(game, game->south, game->sprite.south);
	init_sprites(game, game->east, game->sprite.east);
	init_sprites(game, game->west, game->sprite.west);
}
