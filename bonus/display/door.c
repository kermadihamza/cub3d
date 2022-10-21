/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:35:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/21 16:48:42 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_door(t_game *game, t_ray *ray, double y)
{
	int	color;

	color = find_color_in_sprite(ray, y, game->sprite.door);
	// printf("%x\n", color);
	// printf("x %d, y %f\n", ray->pos_in_screen, y);
	ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, color);
}

void	display_door(t_game *game, t_evil *door)
{
	int		i;
	t_pos	origin;

	i = 0;
	while (i < game->nb_door)
	{
		init_evil_values(game, &game->door[i]);
		i++;
	}
	i = 0;
	while (i < game->nb_door)
	{
		origin.x = (door[i].angle_from_player + game->fov / 2) / game->fov * WIN_W;
		origin.y = (WIN_H / 2) - (door[i].scale.y / 2);
		print_evil(game, origin, door[i], game->sprite.door);
		i++;
	}
}
