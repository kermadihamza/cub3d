/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/14 18:20:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_ray(t_game *game, double angle)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(angle);
	by = sin(angle);
	d = 0;
	if (bx < 0.05 && bx > -0.05)
		bx = 0.05;
	pente = by / bx;
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= 1)
	{
		mlx_pixel_put(game->mlx, game->win, (game->player.x * 10 + 5) - d * pente, (game->player.y * 10 + 5) + d, 0xFF00000);
		if (bx < 0)
			d -= 0.025;
		else
			d += 0.025;
	}
}

void	check_horizontal(t_game *game, t_ray *ray, t_pos player)
{
	int		i;
	double	aTan;
	char	**map;

	i = 0;
	while (i < 1)
	{
		ray->dof = 0;
		aTan = -1 / tan(ray->ray_angle);
		if (ray->ray_angle > PI) // looking up
		{
			ray->ray_y = floor(player.y); // arondir a la valeur au dessus -> utiliser la fonction floor (ou ceil)
			ray->ray_x = (player.y - ray->ray_y) * aTan + player.x;
			ray->yo = -1; // c quoi l'offset ??? le décalage entre la case et la case suivant où on va cogner un mur -> 1 ?
			ray->xo = -ray->yo * aTan;  // avec la tangente on calcule l'offset x (combien on avance dans les x entre deux croisement en y)
		}
		if (ray->ray_angle < PI) // looking down
		{
			ray->ray_y = ceil(player.y); // arondir a la valeur en dessous 
			ray->ray_x = (player.y - ray->ray_y) * aTan + player.x;
			ray->yo = 1;
			ray->xo -= ray->yo * aTan;
	// printf("angle:%f\n", ray->ray_angle);
	// printf("aTan:%f\n", aTan);
	// printf("xo:%f\n", ray->xo);
	// printf("yo:%f\n", ray->yo);
		}
		if (ray->ray_angle == 0 || ray->ray_angle == PI)
		{
			ray->ray_x = player.x;
			ray->ray_y = player.y;
			ray->dof = 8;
		}
		i++;
		map = ft_split(game->map, '\n');
		while (ray->dof < 8) // depth of field, pour nous combien ? fade ?
		// infos de la map, comparer la position oú arrive le rayon avec la carte et regarder si c'est un mur
		// si on croise un mur on arrête la boucle, sinon on augmente la position du rayon avec l'offset et on se retrouve a la case d'après
		// /!\ protéger en vérifiant que le rayon ne sort pas de la map pour ne pas segfault
		{
		// 	draw_ray(game, ray->p_angle);
			if (map[(int)ray->ray_x][(int)ray->ray_y] && map[(int)ray->ray_x][(int)ray->ray_y] == '1')
				ray->dof = 8;
			else
			{
				ray->ray_x += ray->xo;
				ray->ray_y += ray->yo;
			}
			ray->dof ++;
		}
		printf("x, y : %f, %f\n", ray->ray_x, ray->ray_y);
	(void) game;
	(void) map;
	}
}

void	ray_test(t_game *game, t_ray *ray, t_pos player)
{
	ray->ray_angle = ray->p_angle;
	check_horizontal(game, ray, player);
}
