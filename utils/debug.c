/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:11:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/06 17:52:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_game *game)
{
	printf("NO ->%s\n", game->north);
	printf("SO ->%s\n", game->south);
	printf("WE ->%s\n", game->west);
	printf("EA ->%s\n", game->east);
	printf("F ->%s\n", game->floor);
	printf("C ->%s\n", game->roof);
	printf("player_dir ->%c\n", game->player_dir);
	printf("F color ->%d\n", game->color_floor);
	printf("C color ->%d\n\n", game->color_roof);
	printf("map ->%s\n", game->map);
}

void	debug_ray(t_ray *ray)
{
	printf("p_angle ->%f\n", ray->p_angle);
	printf("adj_x ->%f\n", ray->adj_x);
	printf("adj_y ->%f\n", ray->adj_y);
	printf("ra ->%f\n", ray->ra);
	printf("ray len ->%f\n\n", ray->ray_len);
	printf("step_x ->%d\n", ray->step_x);
	printf("step_y ->%d\n", ray->step_y);
	printf("delta_x ->%f\n", ray->delta_x);
	printf("delta_y ->%f\n", ray->delta_y);
	printf("tile.x ->%f\n", ray->tile.x);
	printf("tile.y ->%f\n", ray->tile.y);
	printf("hor ->%d\n", ray->hor);
	printf("pos_in_screen ->%d\n", ray->pos_in_screen);
}

void	debug_img(t_img img)
{
	printf("img ->%p\n", img.img);
	printf("addr ->%s\n", img.addr);
	printf("bpp ->%d\n", img.bpp);
	printf("line_length ->%d\n", img.line_length);
	printf("endian ->%d\n\n", img.endian);
}

void	debug_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("->%s\n", split[i]);
		i++;
	}	
}

void	debug_pos(t_pos pos)
{
	printf("x : %f\n", pos.x);
	printf("y : %f\n", pos.y);
}
