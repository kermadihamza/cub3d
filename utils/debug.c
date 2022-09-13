/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:11:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/13 21:42:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	debug(t_game *game)
{
	printf("NO ->%s\n", game->north);
	printf("SO ->%s\n", game->south);
	printf("WE ->%s\n", game->west);
	printf("EA ->%s\n", game->east);
	printf("F ->%s\n", game->floor);
	printf("C ->%s\n", game->roof);
	printf("F color ->%d\n", game->color_floor);
	printf("C color ->%d\n\n", game->color_roof);
	printf("map ->%s\n", game->map);
}

void	debug_color(t_color *color)
{
	printf("img ->%p\n", color->img);
	printf("addr ->%s\n", color->addr);
	printf("bpp ->%d\n", color->bpp);
	printf("line_length ->%d\n", color->line_length);
	printf("endian ->%d\n\n", color->endian);
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
