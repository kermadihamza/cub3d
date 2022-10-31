/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:57:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/31 11:26:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*routine_bg(void *arg)
{
	int		i;
	int		start;
	int		end;
	t_game *game;

	i = ((t_arg *)arg)->i;
	game = ((t_arg *)arg)->game;
	start = (WIN_W / N_THREAD) * i;
	end = start + (WIN_W / N_THREAD);
	sprite_factory(game);
	// init_color(&game->img, game->color_floor, 'F');
	// init_color(&game->img, game->color_roof, 'C');
	return (arg);
}

void	*routine_raycasting(void *arg)
{
	int		i;
	int		start;
	int		end;
	t_game *game;

	i = ((t_arg *)arg)->i;
	game = ((t_arg *)arg)->game;
	start = (WIN_W / N_THREAD) * i;
	end = start + (WIN_W / N_THREAD);
	// printf("start %d\n", start);
	// printf("end   %d\n", end);
	raycasting(game, &game->ray, start, end);
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
		if (pthread_create(&tid[i], NULL, routine, arg) != 0)
			handle_errors(game, MALLOC_F, NULL);
		i++;
	}
	i = 0;
	while (i < N_THREAD)
	{
		if (pthread_join(tid[i], (void **)&arg) != 0)
			handle_errors(game, MALLOC_F, NULL);
		free (arg);
		i++;
	}
}