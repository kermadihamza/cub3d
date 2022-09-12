/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 14:26:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*roof;
	int		color_floor;
	int		color_roof;
	char	*map;
}	t_game;

void	parsing(t_game *game, int ac, char **av);

void	debug(t_game *game);
void	debug_split(char **split);

#endif