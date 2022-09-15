/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/15 17:47:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	little_square_2(t_game *game, int color, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx, game->win, pos.x *10 + i , pos.y * 10 + j, color);
			j++;
		}	
		i++;
	}
}
	// printf("play ->%f\n", player.x);

	// printf("rx --->%f\n", ray->rx);
	// printf("ry --->%f\n", ray->ry);
	// printf("first->%f = %f * %f\n", ray->first_yo, tan(ray->ra), ray->first_xo);
	// printf("ra : %f\n", ray->ra);
	// printf("player_a : %f\n", ray->p_angle);
	

	// printf("rx : %f\n", ray->rx);

void	init_up_values(t_game *game, t_ray *ray, t_pos player)
{
	if (ray->ra > PI / 2)
		ray->rx = floor(player.x);
	else
		ray->rx = ceil(player.x);
	ray->first_xo = ray->rx - player.x;	
	ray->first_yo = fabs(tan(ray->ra)) * ray->first_xo;
	ray->ry = player.y - ray->first_yo - ray->yo;

	ray->xo = 1;
	ray->yo = fabs(tan(ray->ra));
	t_pos	pos;
	pos.x = ray->rx;
	pos.y = ray->ry;
	little_square_2(game, 0x00FF00, pos);
}
	
void	init_down_values(t_game *game, t_ray *ray, t_pos player)
{
	if (ray->ra < (3 * PI) / 2)
		ray->rx = floor(player.x);
	else
		ray->rx = ceil(player.x);
	ray->first_xo = ray->rx - player.x;	
	ray->first_yo = -fabs(tan(ray->ra)) * ray->first_xo;
	ray->ry = player.y- ray->first_yo - ray->yo;

	ray->xo = 1;
	ray->yo = -fabs(tan(ray->ra));
	(void) game;
	t_pos	pos;
	pos.x = ray->rx;
	pos.y = ray->ry;
	little_square_2(game, 0x00FF00, pos);
}

void	check_vertical(t_game *game, t_ray *ray, t_pos player)
{
	int		i;
	int		dof;
	char	**map;

	i = 0;
	dof = 0;
	map = ft_split(game->map, '\n');
	while (i < 1)
	{
		ray->ra = ray->p_angle;
		if (ray->ra < PI) // looking up
			init_up_values(game, ray, player);
		if (ray->ra > PI) // looking down
			init_down_values(game, ray, player);
		if (ray->ra == 0 || ray->ra == PI)
		{
			ray->rx = player.x;
			ray->ry = player.y;
		}
		i++;
	}
	while (dof < 8)
	{
		if (map[(int)ray->rx][(int)ray->ry] && map[(int)ray->rx][(int)ray->ry] == '1')
			dof = 8;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
		}
		dof ++;
	}
	// t_pos pos;
	// pos.x = ray->rx;
	// pos.y = ray->ry;
}

void	ray_test(t_game *game, t_ray *ray, t_pos player)
{
	check_vertical(game, ray, player);
}
