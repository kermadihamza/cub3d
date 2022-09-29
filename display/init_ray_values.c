/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:59:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/29 19:24:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_values(t_ray *ray, t_pos player)
{
	(void) player;
	ray->delta_x = fabs(1 / cos(ray->ra));
	ray->delta_y = fabs(1 / sin(ray->ra));
	// if (ray->ra < M_PI)
	// 	ray->step_y = -1;
	// else
	// 	ray->step_y = 1;
	// if (ray->ra > M_PI / 2 && ray->ra < (3 * M_PI) / 2)
	// 	ray->step_x = -1;
	// else if (ray->ra < M_PI / 2 || ray->ra > (3 * M_PI) / 2)
	// 	ray->step_x = 1;
	if (sin(ray->ra) < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (cos(ray->ra) < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
}
