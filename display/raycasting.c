/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/21 13:25:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perfect_angles(t_ray *ray)
{
	if (ray->ra == 0 || ray->ra == 2 * M_PI)
		ray->v.x++;
	else if (ray->ra == M_PI / 2)
		ray->h.y--;
	else if (ray->ra == M_PI)
		ray->h.x--;
	else if (ray->ra == (3 * M_PI) / 2)
		ray->h.y++;
}

void	move_on(t_game *game, t_ray *ray, int i)
{
	if (i == 0)
	{
		if (is_hor_closer(game, ray))
			ray->h.x += ray->first_xo;
		else
			ray->v.y += ray->first_yo;
	}
	else
	{
		if (is_hor_closer(game, ray))
			ray->h.x += ray->xo;
		else
			ray->v.y += ray->yo;
	}
	if (is_hor_closer(game, ray) && ray->ra < M_PI)
		ray->h.y -= 1;
	else if (is_hor_closer(game, ray) && ray->ra > M_PI)
		ray->h.y += 1;
	else if (!is_hor_closer(game, ray) && ray->ra > M_PI / 2 && ray->ra < (3 * M_PI) / 2)
		ray->v.x -= 1;
	else if (!is_hor_closer(game, ray) && (ray->ra < M_PI / 2 || ray->ra < (3 * M_PI) / 2))
		ray->v.x += 1;
}

void	check_wall(t_game *game, t_ray *ray, t_pos player)
{
	int		dof;

	dof = 0;
	ray->h.x = player.x;
	ray->h.y = player.y;
	ray->v.x = player.x;
	ray->v.y = player.y;
	while (dof < 10)
	{
		if (is_wall(game, (int)ray->h.x, (int)ray->h.y)
			|| is_wall(game, (int)ray->v.x, (int)ray->v.y))
		{
			set_final_pos(game, ray);
			dof = 10;
		}
		else if (is_perfect_angle(ray->ra))
			perfect_angles(ray);
		else
			move_on(game, ray, 0);
		dof ++;
	}
	print_ray(game, ray);
}

void	ray_test(t_game *game, t_ray *ray, t_pos player)
{
	double	small;

	ray->pos_in_screen = 0;
	small = -1.5;
	ray->ray_len = -1;
	while (ray->pos_in_screen < 60)
	{
		ray->ra = ray->p_angle + small;
		init_vertical_values(ray, player);
		init_horizontal_values(ray, player);
		check_wall(game, ray, player);
		small += 0.05;
		ray->pos_in_screen++;
	}
}
