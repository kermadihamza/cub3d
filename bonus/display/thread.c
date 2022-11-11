/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:57:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/08 18:51:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*routine_bg(void *arg)
{
	int		i;
	int		start;
	int		end;
	t_game	*game;

	i = ((t_arg *)arg)->i;
	game = ((t_arg *)arg)->game;
	start = (WIN_W / N_THREAD) * i;
	end = start + (WIN_W / N_THREAD);
	display_floor_roof(game, start, end);
	return (arg);
}

void	*routine_raycasting(void *arg)
{
	int		i;
	int		start;
	int		end;
	t_game	*game;

	i = ((t_arg *)arg)->i;
	game = ((t_arg *)arg)->game;
	start = (WIN_W / N_THREAD) * i;
	end = start + (WIN_W / N_THREAD);
	game->ray[i].door_tile = posi(0, 0);
	game->ray[i].door = -1;
	game->ray[i].door_hor = -1;
	game->ray[i].door_vert = -1;
	game->ray[i].pos_in_screen = 0;
	raycasting(game, game->ray + i, start, end);
	return (arg);
}

void	thread(t_game *game, void *(*routine)(void *))
{
	int			i;
	t_arg		*arg;
	pthread_t	tid[N_THREAD];

	i = 0;
	while (i < N_THREAD)
	{
		arg = malloc(sizeof(t_arg));
		if (!arg)
			handle_errors(game, MALLOC_F, NULL);
		arg->game = game;
		arg->i = i;
		if (pthread_create(&tid[i], NULL, routine, arg))
			handle_errors(game, MALLOC_F, NULL);
		i++;
	}
	i = 0;
	while (i < N_THREAD)
	{
		if (pthread_join(tid[i], (void **)&arg))
			handle_errors(game, MALLOC_F, NULL);
		free (arg);
		i++;
	}
}
