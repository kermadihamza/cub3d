/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:30:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 12:30:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	find_pos(char *map, int i)
{
	int		j;
	int		count;
	t_pos	pos;

	j = i;
	count = 0;
	while (j >= 0)
	{
		if (map[j] == '\n')
			count++;
		if (map[j] == '\n' && count == 1)
			pos.x = i - j - 1 + 0.05;
		j--;
	}	
	pos.y = count + 0.05;
	return (pos);
}

void	add_new_pos(t_pos *pos, double x, double y)
{
	pos->x += x;
	pos->y += y;
}

t_pos	pos(double	x, double y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}
