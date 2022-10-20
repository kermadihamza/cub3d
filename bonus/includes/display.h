/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:53 by hakermad          #+#    #+#             */
/*   Updated: 2022/10/20 22:13:59 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	ft_mlx_pixel_put(t_img *img, int x, int y, int num_color);
int		display(t_game *game);
void	init_mini_map(t_game *game);
void	raycasting(t_game *game, t_ray *ray, t_pos player);
void	init_ray_values(t_ray *ray);
double	check_wall_vert(t_game *game, t_ray *ray, t_pos player);
double	check_wall_hor(t_game *game, t_ray *ray, t_pos player);
void	print_ray(t_game *game, t_ray *ray);
void	ft_draw_line(t_game *game, double angle, t_pos pos, int len);
void	init_color_sprite(t_game *game);
int		find_color_in_sprite(t_ray *ray, double y, t_img sprite);
int		get_color(t_img sprite, t_pos pos);

int		key_press(int code, t_game *game);
int		key_release(int code, t_game *game);
void	key_manager(t_game *game, t_ray *ray, t_key key);

void	display_evil(t_game *game, t_evil *evil);
t_pos	get_pos(t_pos pos, t_pos size, t_img sprite);
t_pos	calculate_size_on_screen(t_evil evil, t_img	evil_sprite);
void	init_evil_values(t_game *game, t_evil *evil);

void	display_player(t_game *game, t_img sprite);
void	numbers(t_game *game);

#endif
