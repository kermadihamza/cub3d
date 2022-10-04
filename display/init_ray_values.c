/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:59:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/04 16:34:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_values(t_ray *ray)
{
	if (ray->ra >= 2 * M_PI)
		ray->ra -= 2 * M_PI;
	else if (ray->ra < 0)
		ray->ra += 2 * M_PI;
	ray->delta_x = fabs(1 / cos(ray->ra));
	ray->delta_y = fabs(1 / sin(ray->ra));
	if (sin(ray->ra) < 0) // regarde vers le bas
		ray->step_y = 1;
	else
		ray->step_y = -1;
	if (cos(ray->ra) < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	ray->hor = 0;
}
