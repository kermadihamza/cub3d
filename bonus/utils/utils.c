/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:35:49 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 17:48:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_hor_closer(double hor, double vert)
{
	return ((hor < vert && hor && vert) || !vert);
}

int	is_map_letter(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0'
		|| c == '1' || c == 'M' || c == 'P' || c == ' ' || c == '\n');
}

int	is_personage(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_destroy_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
		free (game->map);
	if (game->s_map)
		free_split(game->s_map);
	mlx_destroy_window(game->mlx, game->win);
	free (game->mlx);
	system ("killall afplay");
	exit (EXIT_SUCCESS);
	return (0);
}
