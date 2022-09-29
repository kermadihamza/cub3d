/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/29 20:26:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_outside_map(int x, int y, char **map)
{
	return (y < 0 || y > max_vert(map) || x < 0 || x > max_hor(map, y));
}

int	is_wall(t_game *game, int x, int y)
{
	if (!is_outside_map(x, y, game->s_map) && game->s_map[y][x]
		&& game->s_map[y][x] == '1')
		return (1);
	return (0);
}

void	calcul_ray_len(t_ray *ray, t_pos player, t_pos *pos, double *len)
{
	double	opp;

	opp = pos->x - player.x;
	*len = opp / (sin(ray->ra));
}
