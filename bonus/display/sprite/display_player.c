/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:46:57 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 14:17:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_player(t_game *game, t_img sprite)
{
	t_pos	pos;
	t_pos	origin;
	int		mult;

	if (game->key.third_p == 0)
		return ;
	pos.y = 0;
	mult = 10;
	origin = posi(WIN_W / 2 - (sprite.width * mult) / 2,
			WIN_H - (sprite.height * mult));
	display_one_img(game, mult, sprite, origin);
}
