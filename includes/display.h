/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:53 by hakermad          #+#    #+#             */
/*   Updated: 2022/09/20 16:43:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	ft_mlx_pixel_put(t_img *img, int x, int y, int num_color);
int		display(t_game *game);
void	init_mini_map(t_game *game);
void	ray_test(t_game *game, t_ray *ray, t_pos player);
void	init_vertical_values(t_ray *ray, t_pos player);
void	init_horizontal_values(t_ray *ray, t_pos player);
void	print_ray(t_game *game, t_ray *ray);
void	ft_draw_line(t_game *game, double angle, t_pos pos, int len);
void	init_color_sprite(t_game *game);

int		key_press(int code, t_game *game);
int		key_release(int code, t_key *key);
void	key_manager(t_game *game, t_key key);

#endif
