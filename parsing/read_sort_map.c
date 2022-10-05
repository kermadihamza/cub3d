/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sort_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:44:18 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/05 15:48:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*copy_infos(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] == ' ' && src[i] == '	')
		i++;
	if (src[i] == ' ' || src[i] == '	')
		i++;
	dest = ft_strdup(src + i);
	i = 0;
	while (dest[i] != '\n')
		i++;
	if (dest[i] == '\n')
		dest[i] = '\0';
	return (dest);
}

void	sort_map_infos(t_game *game, char *str)
{
	if (!str[0])
		return ;
	else if (str[0] == '1' || str[0] == '0'
		|| str[0] == ' ' || game->map[0] != '\0')
		game->map = ft_strjoin(game->map, str);
	else if (is_personage(str[0]) && str[1] && (str[1] == '0' || str[1] == '1'))
		game->map = ft_strjoin(game->map, str);
	else if (str[0] == 'N' && str[1] && str[1] == 'O' && !game->north)
		game->north = copy_infos(str + 2);
	else if (str[0] == 'S' && str[1] && str[1] == 'O' && !game->south)
		game->south = copy_infos(str + 2);
	else if (str[0] == 'E' && str[1] && str[1] == 'A' && !game->east)
		game->east = copy_infos(str + 2);
	else if (str[0] == 'W' && str[1] && str[1] == 'E' && !game->west)
		game->west = copy_infos(str + 2);
	else if (str[0] == 'F' && !game->floor)
		game->floor = copy_infos(str + 1);
	else if (str[0] == 'C' && !game->roof)
		game->roof = copy_infos(str + 1);
	else if (str[0] != '\n')
		handle_errors(game, SYNTAX_ERR, str);
}

void	read_map(t_game *game, char *file)
{
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		handle_errors(game, UNEXIST_MAP, NULL);
	game->map = malloc(sizeof (char) * 1);
	if (!game->map)
		handle_errors(game, MALLOC_F, NULL);
	game->map[0] = '\0';
	while (game->map)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		sort_map_infos(game, buffer);
		if (buffer)
			free (buffer);
	}
}
