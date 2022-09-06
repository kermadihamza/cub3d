/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:49:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 19:15:59 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	sides(char *map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		if (map[i] == '0' || is_personage(map[i]))
		{
			if (map[i - 1] && (map[i - 1] == ' ' || map[i - 1] == '\n'))
				handle_errors(OPEN_WALL, map);
			else if ((map[i + 1] && (map[i + 1] == '\n'
				|| map[i + 1] == ' ')) || !map[i + 1])
				handle_errors(OPEN_WALL, map);
		}
		i++;
	}
}

// void	bottom(char *map)
// {
// 	int	prev_len;
// 	int	len;

// 	prev_len = 0;
// 	len = 0;
// 			else if (len > prev_len)
// 				handle_errors(OPEN_WALL, map);
// 		if (map[i] == '\n')
// 		{
// 			prev_len = len;
// 			len = 0;
// 		}
// 		len++;
// }

void	holes_in_walls(char *map)
{
	sides(map);
	// bottom(map);
}
