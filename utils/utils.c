/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:35:49 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/05 16:03:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_new_pos(t_pos *pos, double x, double y)
{
	pos->x += x;
	pos->y += y;
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
	int		i;

	i = 0;
	if (game->map)
		free (game->map);
	if (game->s_map)
		free_split(game->s_map);
	mlx_destroy_window(game->mlx, game->win);
	free (game->mlx);
	exit (EXIT_SUCCESS);
	return (0);
}
