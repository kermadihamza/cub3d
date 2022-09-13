/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:30:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/13 21:42:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			pos.x = i - j - 1;
		j--;
	}	
	pos.y = count;
	return (pos);
}
