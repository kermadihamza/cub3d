/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:41:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 17:06:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

void	initialization(t_game *game);

void	init_height_width(t_game *game, t_sprite *sprite);
void	init_color_sprite(t_game *game);
void	init_color(t_img *img, int num_color, char c);
void	init_sprites(t_game *game, char *path, t_img *sprite);
void	ft_new_image_blt(t_game *game, t_img *src, t_img *dst, t_pos start);

void	init_player_pos(t_game *game, t_player *p);
void	init_ray_values(t_ray *ray);
void	init_evil_pos(t_game *game);
void	init_evil_values(t_game *game, t_evil *evil);
void	init_door_pos(t_game *game);
void	door_re_init(t_ray *ray);

#endif
