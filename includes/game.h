/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/12 19:29:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_color {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_color;

typedef struct s_sprite {
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*floor;
	char		*roof;
	int			color_floor;
	int			color_roof;
	char		*map;
	t_color		color[2];			// 0 = floor et 1 = roof
	t_sprite	sprite;
}	t_game;

void	debug(t_game *game);
void	debug_color(t_color *color);
void	debug_split(char **split);

#endif