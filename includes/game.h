/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 17:53:52 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

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
	t_img	color[2];			// 0 = floor et 1 = roof
	t_img	sprite[4];
}	t_game;

void	parsing(t_game *game, int ac, char **av);

void	debug(t_game *game);
void	debug_img(t_img *img);
void	debug_split(char **split);

#endif