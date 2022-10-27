/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:57:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/27 20:23:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*routine(t_arg *arg)
{
	return (arg);
}

void	thread(t_game *game)
{
	int		i;
	t_arg	*arg;

	i = 0;
	arg = malloc(sizeof(t_arg));
	if (!arg)
		handle_errors(game, MALLOC_F, NULL);
	game->tid = malloc(sizeof(pthread_t) * N_THREAD);
	if (!game->tid)
		handle_errors(game, MALLOC_F, NULL);
	while (i < N_THREAD)
	{
		arg->i = i;
		arg->game = game;
		if (pthread_create(&game->tid[i], NULL, (void *)routine, arg) != 0)
			handle_errors(game, MALLOC_F, NULL);
		// free (arg);
		i++;
	}
	i = 0;
	while (i < N_THREAD)
	{
		if (pthread_join(game->tid[i], NULL) != 0)
			handle_errors(game, MALLOC_F, NULL);
		i++;
	}
}
