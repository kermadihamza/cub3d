/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:06:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 16:38:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_img sprite, t_pos pos)
{
	char	*tab;
	int		color;

	color = 0;
	if (pos.x >= 0 && pos.x <= sprite.width && pos.y >= 0
		&& pos.y <= sprite.height)
	{
		tab = sprite.addr + ((int)pos.y * sprite.line_length + (int)pos.x
				* (sprite.bpp / 8));
		color = *(unsigned int *)tab;
	}
	return (color);
}

int	find_color_in_sprite(t_ray *ray, double y, t_img sprite)
{
	double	expand_y;
	double	percent_y;
	double	wall_min_y;
	t_pos	pos;
	double	unit_hor;

	unit_hor = sprite.width / sprite.height;
	if (ray->hor == 1)
		pos.x = ray->tile_hor.x
			- (floor(ray->tile_hor.x / unit_hor) * unit_hor);
	else
		pos.x = ray->tile_vert.y
			- (floor(ray->tile_vert.y / unit_hor) * unit_hor);
	pos.x *= sprite.width / unit_hor;
	expand_y = WIN_H / sprite.height + 1;
	percent_y = (WIN_H / ray->ray_len) / WIN_H;
	wall_min_y = (WIN_H / 2) - (WIN_H / ray->ray_len) / 2;
	pos.y = ((y - wall_min_y) / percent_y) / expand_y;
	return (get_color(sprite, pos));
}
