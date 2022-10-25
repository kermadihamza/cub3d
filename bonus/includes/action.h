/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:02:13 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 21:22:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

void	action(t_game *game, t_ray *ray, t_key key);
void	attack(t_game *game, t_player *p, t_evil *evil);
void	move(t_game *game, t_ray *ray, t_key key);
void	angle_changes(t_game *game, t_ray *ray);
void	handle_weapon(t_player *p);
int		key_press(int code, t_game *game);
int		key_release(int code, t_game *game);
int		animation(t_game *game);

#endif
