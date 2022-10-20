/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 12:09:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

typedef struct s_ray {
	double	adj_x;
	double	adj_y;
	double	ra;
	double	ray_len;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	t_pos	tile_vert;
	t_pos	tile_hor;
	int		hor;
	int		pos_in_screen;
}	t_ray;

typedef struct s_rect {
	int	x;
	int	y;
	int	width;
	int	height;
} t_rect;

typedef struct s_img {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	double	height;
	double	width;
}	t_img;

typedef struct s_sprite {
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	all_sprites;
	t_img	evil;
	double	width;
	double	height;
}	t_sprite;

typedef struct s_evil {
	double	dist_player_left;
	double	dist_player_right;
	double	angle_from_player;
	t_pos	pos;
}	t_evil;

typedef struct s_key {
	bool	a;
	bool	s;
	bool	w;
	bool	d;
	bool	turn_l;
	bool	turn_r;
}	t_key;

typedef struct s_player {
	t_pos	pos;
	char	dir;
	double	angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*floor;
	char		*roof;
	int			color_floor;
	int			color_roof;
	char		*map;
	char		**s_map;
	int			nb_evil;
	t_evil		*evil;
	t_img		img;
	t_sprite	sprite;
	t_key		key;
	t_ray		ray;
	t_player	player;
}	t_game;

void	debug(t_game *game);
void	debug_img(t_img img);
void	debug_split(char **split);
void	debug_pos(t_pos pos);
void	debug_ray(t_ray *ray);

#endif