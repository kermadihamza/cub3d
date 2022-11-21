/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:01 by lrondia           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/18 18:14:55 by lrondia          ###   ########.fr       */
=======
/*   Updated: 2022/11/16 18:11:50 by hakermad         ###   ########.fr       */
>>>>>>> aef2e7c457a380854c9281f10b5e553bc6f7f2e1
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_error_name(t_game *game, char *av)
{
	int		i;
	int		j;
	char	end[5];

	i = ft_strlen(av) - 1;
	j = 0;
	while (j < 4 && i > 0)
	{
		end[j] = av[i];
		i--;
		j++;
	}
	end[j] = '\0';
	if (!ft_strcmp(end, "buc."))
		handle_errors(game, WRONG_NAME, av);
}

void	number_of_elements(t_game *game, char *map)
{
	int	i;
	int	character;

	i = 0;
	character = 0;
	while (map[i])
	{
		if (is_personage(map[i]))
		{
			game->player.dir = map[i];
			character++;
		}
		i++;
	}
	if (character != 1)
		handle_errors(game, NB_ELEMENTS, map);
}

void	other_character(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_map_letter(map[i]))
			handle_errors(game, OTHER_CHAR, &map[i]);
		i++;
	}
}

void	check_doors(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if ((map[y - 1] && map[y - 1][x] != '1')
					|| (map[y + 1] && map[y + 1][x] != '1'))
					handle_errors(game, DOOR_WALL, "\n");
			}
			x++;
		}
		y++;
	}
}

void	error_map(t_game *game, char *map)
{
	other_character(game, map);
	number_of_elements(game, map);
	holes_in_walls(game, map);
	check_doors(game, game->s_map);
}
