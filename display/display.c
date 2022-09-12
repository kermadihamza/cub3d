/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/09/12 17:53:34 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_color(t_game *game, t_img *color, int num_color, char c)
{
	int	i;
	int	j;

	color->img = mlx_new_image(game->mlx, 1920, 1080);
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
	if (c == 'F')
		mlx_put_image_to_window(game->mlx, game->win, color->img, 0, 512);
	else
		mlx_put_image_to_window(game->mlx, game->win, color->img, 0, 0);
}

void	add_texture(t_game *game, char c)
{
	if (c == 'F')
		add_color(game, &game->color[0], game->color_floor, c);
	else if (c == 'C')
		add_color(game, &game->color[1], game->color_roof, c);
	// else
	// 	add_sprites(game);
}

void	display(t_game *game)
{
	add_texture(game, 'C');
	add_texture(game, 'F');
}
