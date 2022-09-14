/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/14 17:04:58 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	angle_changes(int code, t_ray *ray)
{
	if (code == 123)
	{
		ray->p_angle -= 0.1;
		if (ray->p_angle < 0)
			ray->p_angle += 2*PI;
		ray->delta_x = cos(ray->p_angle);
		ray->delta_y = sin(ray->p_angle);
	}
	if (code == 124)
	{
		ray->p_angle += 0.1;
		if (ray->p_angle > 2*PI)
			ray->p_angle -= 2*PI;
		ray->delta_x = cos(ray->p_angle);
		ray->delta_y = sin(ray->p_angle);
	}
}

// int	block_wall(int code, t_game *game)
// {
// 	t_pos pos;
	
// 	if ((code == 2) && game->map[(int)(pos.x + 0.1) / 0.1] == '1')
// 		return (0);
// 	else if ((code == 0) && game->map[pos.y / 0.1]
// 		[(pos.x - 0.1) / 0.1] == '1')
// 		return (0);
// 	else if ((code == 13) && game->map[(pos.y - 0.1) / 0.1]
// 		[pos.x / 0.1] == '1')
// 		return (0);
// 	else if ((code == 1) && game->map[(pos.y + 0.1) / 0.1]
// 		[pos.x / 0.1] == '1')
// 		return (0);
// 	return (1);
// }

int	is_rounded(t_game *game)
{
	ft_split(game->map, '\n');
	// player.x = position du joueur
	printf("ok\n %s", game->map);
	return (1);
}

int	is_wall(t_game *game, char **maps, float x, float y)
{
	int	rx;
	int	ry;

	//printf("py is %f\n", data->py);
	ry = y / game->sy;
	rx = x / game->sx;
	//printf("rx is %d, ry is %d\n", rx, ry);
	//printf("map[%d][%d] is %c\n", ry, rx, maps[ry][rx]);
	//printf("px is %f, py is %f\n", data->px, data->py);
	if (maps[ry][rx] && maps[ry][rx] != '1')
		return (1);
	return (0);
}

int	key_press(int code, t_game *game)
{

	if (code == 53)
		exit (EXIT_SUCCESS);
	if (code == 0) // a
		game->key.a = 1;
	if (code == 1) // s
		game->key.s = 1;
	if (code == 13) // W
		game->key.w = 1;
	if (code == 2) // D
		game->key.d = 1;
	angle_changes(code, &game->ray);
	return (0);
}

int	key_release(int code, t_key *key)
{
	if (code == 0)
		key->a = 0;
	if (code == 1)
		key->s = 0;
	if (code == 13)
		key->w = 0;
	if (code == 2)
		key->d = 0;
	return (0);
}

void	key_manager(t_game *game, t_key key)
{
	//t_pos pos;

	if (key.a == 1 && is_rounded(game))
		game->player.x -= 0.1;
	if (key.s == 1)
		game->player.y += 0.1;
	if (key.w == 1)
		game->player.y -= 0.1;
	if (key.d == 1)
		game->player.x += 0.1;
}

int	display(t_game *game)
{
	key_manager(game, game->key);
	init_mini_map(game);
	return (0);
}
