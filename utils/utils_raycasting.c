/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 19:08:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_game *game, int x, int y)
{
	char	**map;
	
	map = ft_split(game->map, '\n');
	if (y > 0 && y < max_vert(map) - 1 && map[y][x] && map[y][x] == '1')
	{
		free_split(map);
		return (1);
	}
	return (0);
}

void	calcul_ray_len(t_ray *ray, t_pos player, t_pos *pos, double *len)
{
	double	opp;

	opp = pos->x - player.x;
	*len = opp / (sin(ray->ra));
}

int	is_hor_closer(t_game *game, t_ray *ray)
{
	double	hor_adj;
	double	vert_adj;
	double	hor_len;
	double	vert_len;

	hor_adj = ray->h.x - game->player.x;	
	vert_adj = ray->v.x - game->player.x;	
	hor_len = hor_adj / cos(ray->ra);	
	vert_len = vert_adj / cos(ray->ra);	
	if (hor_len <= vert_len)
		return (1);
	else
		return (0);
}

void	set_final_pos(t_game *game, t_ray *ray)
{
	if (is_hor_closer(game, ray))
	{
		ray->r.x = ray->h.x;
		ray->r.y = ray->h.y;
	}
	else
	{
		ray->r.x = ray->v.x;
		ray->r.y = ray->v.y;
	}
}
