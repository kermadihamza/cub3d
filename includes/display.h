/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:53 by hakermad          #+#    #+#             */
/*   Updated: 2022/09/13 21:21:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

void	ft_mlx_pixel_put(t_color *color, int x, int y, int num_color);
int		display(t_game *game);
void	init_mini_map(t_game *game);

int		key_press(int code, t_key *key);
int		key_release(int code, t_key *key);
void	key_manager(t_game *game, t_key key);

#endif
