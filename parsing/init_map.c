/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:19:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 12:18:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	read_map_file(t_game *game, char *file)
{
	int		fd;
	char	*buffer;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_errors(UNEXIST_MAP, NULL);
	game->map = malloc(sizeof (char) * 1);
	if (!game->map)
		handle_errors(MALLOC_F, NULL);
	game->map[0] = '\0';
	while (game->map)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map = ft_strjoin(game->map, buffer);
		if (!game->map)
			handle_errors(MALLOC_F, NULL);
		if (buffer)
			free (buffer);
	}	
}

void	init_map(t_game *game, char **av)
{
	check_error_name(av[1]);
	read_map_file(game, av[1]);
	// spread_infos_map(game);
}
