/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:07:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 17:30:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	message_new_weapon(t_game *game, t_mess *mess, int dead)
{
	int		mult;
	t_pos	pos;

	mult = 3;
	pos = posi(WIN_W / 2 - (mess->mess_w[0].width / 2) * mult, BANNER_Y);
	if (dead == 1 && mess->fork < 50)
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

void	display_attack(t_game *game, t_player p, t_sprite sprite)
{
	int		i;
	t_pos	pos;

	i = 0;
	pos = posi(WIN_W / 2 + 120, 400);
	while (i < game->nb_evil)
	{
		if (game->mess.damage)
		{
			if (game->mess.damage < 10)
				display_one_img(game, 5, sprite.damage, posi(WIN_W / 2, -60));
			if (p.cur_weapon == 0 && game->mess.damage < 10)
				display_one_img(game, 3.8, sprite.num[1], pos);
			else if (p.cur_weapon == 1 && game->mess.damage < 10)
				display_one_img(game, 3.8, sprite.num[2], pos);
			else if (p.cur_weapon == 2 && game->mess.damage < 10)
				display_one_img(game, 3.8, sprite.num[3], pos);
			else if (p.cur_weapon == 3 && game->mess.damage < 10)
				display_one_img(game, 3.8, sprite.num[5], pos);
			game->mess.damage++;
			if (game->mess.damage >= 15)
				game->mess.damage = 0;
		}
		i++;
	}
}

void	messages(t_game *game)
{
	message_new_weapon(game, &game->mess, game->player.n_dead);
	display_attack(game, game->player, game->sprite);
	if (game->player.life <= 0)
		display_one_img(game, 1, game->sprite.lose, posi(0, 0));
}
