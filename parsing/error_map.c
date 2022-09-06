/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:20:01 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 19:10:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	number_of_elements(char *map)
{
	int	i;
	int	character;

	i = 0;
	character = 0;
	while (map[i])
	{
		if (is_personage(map[i]))
			character++;
		i++;
	}
	if (character != 1)
		handle_errors(NB_ELEMENTS, map);
}

void	other_character(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_personage(map[i]) && map[i] != '0' && map[i] != '1' && map[i] != '\n' && map[i] != ' ')
			handle_errors(OTHER_CHAR, &map[i]);
		i++;
	}
}

void	error_map(char *map)
{
	number_of_elements(map);
	other_character(map);
	holes_in_walls(map);
}
