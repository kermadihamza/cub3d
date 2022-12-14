/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 17:35:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	how_many(char c, char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	door_re_init(t_ray *ray)
{
	ray->door_hor = 0;
	ray->door_vert = 0;
	ray->door = 0;
	ray->door_tile = posi(0, 0);
}

void	init_door_pos(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	game->nb_door = how_many('P', game->map);
	game->door = malloc (sizeof(t_door) * game->nb_door);
	if (!game->door)
		handle_errors(game, MALLOC_F, NULL);
	while (game->map[i] && n < game->nb_door)
	{
		if (game->map[i] == 'P')
		{
			game->door[n].pos = find_pos(game->map, i);
			game->door[n].time = 0;
			game->door[n].open = 0;
			n++;
		}
		i++;
	}
}
