/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:43:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 12:46:45 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_rect	init_rect(int x, int y, int width, int height)
{
	t_rect rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

void	bloc_transfer(t_img *src, t_img *dst, t_pos d, t_rect r)
{
	int		x;
	int		y;
	char	*pixel_dst;
	char	*pixel_src;
	int		color;

	y = 0;
	
	while (y < r.height)
	{
		x = 0;
		while (x < r.width)
		{
			pixel_dst = dst->addr + ((y + (int)d.y) * dst->line_length
					+ (x + (int)d.x) * (dst->bpp / 8));
			pixel_src = src->addr + ((y + r.y) * src->line_length + (x + r.x)
					* (src->bpp / 8));
			color = (*(int *)pixel_src);
			if (x + d.x >= 0 && x + d.x < dst->width)
				*(unsigned int *) pixel_dst = *(unsigned int *) pixel_src;
			x++;
		}
		y++;
	}
}
