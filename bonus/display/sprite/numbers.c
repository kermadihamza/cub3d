/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:33:07 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 12:15:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_table(t_game *game, t_img sprite, t_pos origin)
{
	int	mult;

	mult = 3;
	display_one_img(game, mult, sprite, origin);
}

void	set_number(t_game *game, t_img *num, int i, t_pos origin)
{
	int	mult;

	mult = 3;
	if (i >= 10)
	{
		set_number(game, num, i / 10, posi(origin.x - 16 * mult, origin.y));
		set_number(game, num, i % 10, posi(origin.x, origin.y));
	}
	if (i < 10)
		display_one_img(game, mult, num[i], origin);
}

void	numbers(t_game *g)
{
	set_table(g, g->sprite.table, posi(WIN_W - 250, BANNER_Y));
	set_number(g, g->sprite.num, g->player.n_dead, posi(WIN_W - 150, 50));
}
