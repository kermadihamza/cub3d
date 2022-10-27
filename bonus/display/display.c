/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/27 13:12:42 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
	
void	message_new_weapon(t_game *game, t_mess *mess, int dead)
{
	int		mult;
	t_pos	pos;

	mult = 3;
	pos = posi(WIN_W / 2 - (mess->mess_w[0].width / 2) * mult, BANNER_Y);
	if (dead == 1 && mess->fork < 30)
	{	
		mess->fork ++;
		display_one_img(game, mult, mess->mess_w[0], pos);
	}
	else if (dead == 3 && mess->flame < 50)
	{	
		mess->flame ++;
		display_one_img(game, mult, mess->mess_w[1], pos);
	}
	else if (dead == 6 && mess->morgenstern < 50)
	{	
		mess->morgenstern ++;
		display_one_img(game, mult, mess->mess_w[2], pos);
	}
}

int	display(t_game *game)
{
	sprite_factory(game);
	action(game, &game->ray, game->key);
	door_time(game, game->door);
	raycasting(game, &game->ray, game->player.pos);
	init_mini_map(game);
	display_evil(game, game->evil);
	evil_time(&game->evil[0]);
	numbers(game);
	display_player(game, game->sprite.player);
	message_new_weapon(game, &game->mess, game->player.n_dead);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
