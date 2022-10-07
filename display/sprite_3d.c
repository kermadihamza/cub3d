/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:06:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/07 19:37:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color_in_sprite(t_ray *ray, double y, void *sprite)
{
	char	*tab;
	int		color;
	t_img	img;
	double	expand_x;
	double	expand_y;
	double	percent_x;
	double	percent_y;
	double	wall_min_y = (WIN_H / 2) - (WIN_H /ray->ray_len) / 2;
	double		px_x;
	int		px_y;
	int		fx;

	expand_y = WIN_H / SPRITE_SIZE;
	expand_x = WIN_W / SPRITE_SIZE;
	percent_x = (WIN_W / ray->ray_len) / WIN_W;
	percent_y = (WIN_H / ray->ray_len) / WIN_H;

	if (ray->hor == 1)
		px_x = ray->tile_hor.x - floor(ray->tile_hor.x);
	else
		px_x = ray->tile_vert.y - floor(ray->tile_vert.y);

	fx = px_x * SPRITE_SIZE;
	px_y = ((y - wall_min_y) / percent_y) / expand_y;
	img.addr = mlx_get_data_addr(sprite, &img.bpp, &img.line_length, &img.endian);
	
	
	tab = img.addr + (px_y * img.line_length + fx * (img.bpp / 8));
	color = *(unsigned int*)tab;
	return (color);
}
