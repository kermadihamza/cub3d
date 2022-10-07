/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/07 19:21:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

///////// COMMENTAIRES
// ------> calculs pour les murs verticaux en regardant vers le haut <-------
// ra 	->	ray angle, ra = p_angle - i (ou + i)
// r.x	->	position x, y du rayon a chaque croisement
// 			rx = x arrondi vers le haut (1)
//			ry = y + first yo + yo (4)
// first xo	->	premier offset, plus petit (= xo - x et yo - y)
// 				first xo = rx - x (2)
// 				first yo = tan(ra) * rx (3) 
// xo	->	combien on avance dans les x entre chaque croisement dans les y
//			xo = 1
//			yo = tan(ra) (uniquement quand on regarde les croisements
//				horizontaux, sinon c yo)
// final r	->	coordonnées finales du rayon
// 				final x = x + (n * xo) + first xo
// opposite	->	trigo : coté opposé à l'angle du rayon,
//				permet de calculer la longueur du rayon (meme chose pour adj)
// 				O = (n * yo) + first yo
// len_v	->	ray_len = O / sin (ra)

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
}	t_img;

typedef struct s_sprite {
	void	*north;
	char	*n_path;
	void	*south;
	char	*s_path;
	void	*east;
	char	*e_path;
	void	*west;
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