/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:53 by hakermad          #+#    #+#             */
/*   Updated: 2022/10/27 20:20:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	ft_mlx_pixel_put(t_img *img, int x, int y, int num_color);
int		display(t_game *game);
void	init_mini_map(t_game *game);
void	raycasting(t_game *game, t_ray *ray, t_pos player);
double	check_wall_vert(t_game *game, t_ray *ray, t_pos player);
double	check_wall_hor(t_game *game, t_ray *ray, t_pos player);
void	print_ray(t_game *game, t_ray *ray);
void	ft_draw_line(t_game *game, double angle, t_pos pos, int len);
int		find_color_in_sprite(t_ray *ray, double y, t_img sprite);
int		get_color(t_img sprite, t_pos pos);

void	display_evil(t_game *game, t_evil *evil);
void	evil_time(t_evil *evil);
void	door_time(t_game *game, t_door *door);
void	print_door(t_game *game, t_ray *ray, t_door *door);
void	print_evil(t_game *game, t_pos origin, t_evil evil, t_img sprite);
t_pos	get_pos(t_pos pos, t_pos size, t_img sprite);
t_pos	calculate_size_on_screen(t_evil evil, t_img	evil_sprite);

int		is_hor_closer(double hor, double vert);
void	display_one_img(t_game *game, int mult, t_img sprite, t_pos origin);
void	display_player(t_game *game, t_img sprite);
void	numbers(t_game *game);

void	thread(t_game *game);

#endif
