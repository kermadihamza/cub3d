/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:11:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 15:45:04 by lrondia          ###   ########.fr       */
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
	printf("map ->%s\n", game->map);
}
