/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evil_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:29:40 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 14:43:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	choose_evil_sprite(int time)
{
	if (time < 4)
		return (time);
	else if (time == 4)
		return (3);
	else if (time == 5)
		return (2);
	else if (time == 6)
		return (1);
	else if (time == 7 || time == 8 || time == 15)
		return (0);
	else if (time == 9)
		return (4);
	else if (time == 10)
		return (5);
	else if (time == 11 || time == 12)
		return (6);
	else if (time == 13)
		return (5);
	else if (time == 14)
		return (4);
	else
		return (0);
}

void	evil_time(t_evil *evil)
{
	evil->time++;
	if (evil->time >= 16)
		evil->time = 0;
}
