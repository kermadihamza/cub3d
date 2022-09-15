/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:02:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/15 14:55:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

// typedef struct s_ray {
// 	double	delta_x;
// 	double	delta_y;
// 	double	p_angle;
// 	int		ray;
// 	int		mx;		// map x ?
// 	int		my;
// 	int		mp;
// 	int		dof;	// depth of field (pour ne pas regarder à l'infini et être coincé.e dans une boucle)
// 	double	ray_x;
// 	double	ray_y;
// 	double	ray_angle;
// 	double	xo;		// x offset (on trouve les coordonnées entre la première et la deuxième
// 	double	yo;		// 			intersection avec le mur, comme ça on peut prévoir les suivantes)
// }	t_ray;

typedef struct s_ray {
	double	delta_x;
	double	delta_y;
	double	p_angle;		// -----> calculs pour les murs verticaux en regardant vers le haut <-------

	double	ra;				// ray angle, ra = p_angle - i (ou + i)

	double	rx;				// position x, y du rayon a chaque croisement
	double	ry;				// rx = x arrondi vers le haut (1)
							// ry = y + first yo + yo (4)

	double	first_xo;		// premier offset, plus petit (= xo - x et yo - y)
	double	first_yo;		// first xo = rx - x (2)
							// first yo = tan(ra) * rx (3) 

	double	xo;				// combien on avance dans les x entre chaque croisement dans les y
	double	yo;				// xo = 1
							// yo = tan(ra)

	double	final_rx;		// coordonnées finales du rayon
	double	final_ry;		// final x = x + (n * xo) + first xo

	double	opposite;		// trigo : coté opposé à l'angle du rayon,
	double	adjacent;		// permet de calculer la longueur du rayon (meme chose pour adj)
							// O = (n * yo) + first yo

	double	ray_len;		// ray_len = O / sin (ra)
}	t_ray;

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

typedef struct s_key {
	bool	a;
	bool	s;
	bool	w;
	bool	d;
}	t_key;

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
	t_pos		player;
	t_key		key;
	t_ray		ray;
}	t_game;

void	debug(t_game *game);
void	debug_color(t_color *color);
void	debug_split(char **split);
void	debug_pos(t_pos pos);

#endif