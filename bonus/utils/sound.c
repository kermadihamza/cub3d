/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:54:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/16 13:53:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_sound(t_game *game)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		handle_errors(game, MALLOC_F, NULL);
	if (!pid)
	{
		system("afplay -v 0.5 ./assets/music.mp3");
		exit (EXIT_SUCCESS);
	}
}
