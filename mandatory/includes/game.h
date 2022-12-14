/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 16:22:13 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

typedef struct s_ray {
	double	p_angle;
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

typedef struct s_img {
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
	char	*n_path;
	t_img	south;
	char	*s_path;
	t_img	east;
	char	*e_path;
	t_img	west;
	char	*w_path;
}	t_sprite;

typedef struct s_key {
	bool	a;
	bool	s;
	bool	w;
	bool	d;
	bool	turn_l;
	bool	turn_r;
}	t_key;

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
	char		player_dir;
	t_img		img;
	t_sprite	sprite;
	t_pos		player;
	t_key		key;
	t_ray		ray;
}	t_game;

void	debug(t_game *game);
void	debug_img(t_img img);
void	debug_split(char **split);
void	debug_pos(t_pos pos);
void	debug_ray(t_ray *ray);

#endif