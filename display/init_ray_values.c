/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:59:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 19:32:45 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// PI/2 -> 3*PI/2 (gauche)
// 3pi/2 -> 2pi et 0 -> PI/2 (droite)
// ray->ra < PI (haut)
// else (bas)

void	init_vertical_values(t_ray *ray, t_pos player)
{
	if (ray->ra > M_PI / 2 && ray->ra < (3 * M_PI) / 2)
		ray->r.x = floor(player.x);
	else if (ray->ra > (3 * M_PI) / 2 || ray->ra < M_PI / 2)
		ray->r.x = ceil(player.x);
	if (ray->ra < M_PI)
		ray->first_yo = fabs(tan(ray->ra)) * (ray->r.x - player.x);
	else
		ray->first_yo = -fabs(tan(ray->ra)) * (ray->r.x - player.x);
	if (ray->ra < M_PI)
		ray->yo = fabs(tan(ray->ra));
	else
		ray->yo = -fabs(tan(ray->ra));
}

void	init_horizontal_values(t_ray *ray, t_pos player)
{
	if (ray->ra < M_PI)
		ray->r.y = floor(player.y);
	else if (ray->ra > M_PI)
		ray->r.y = ceil(player.x);
	if (ray->ra < M_PI)
		ray->first_xo = fabs(tan(ray->ra)) * (ray->r.y - player.y);
	else
		ray->first_xo = -fabs(tan(ray->ra)) * (ray->r.y - player.y);
	if (ray->ra < M_PI)
		ray->xo = fabs(tan(ray->ra));
	else
		ray->xo = -fabs(tan(ray->ra));
}
