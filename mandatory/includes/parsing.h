/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:12:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 11:43:33 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define NB_ARGUMENTS 1
# define MALLOC_F 2
# define WRONG_NAME 3
# define MLX_INIT 4
# define UNEXIST_MAP 5
# define SYNTAX_ERR 6
# define NB_ELEMENTS 7
# define OTHER_CHAR 8
# define OPEN_WALL 9
# define INCORR_RGB 10
# define SPRITE_ERR 11
# define PARSE 12

void	init_map(t_game *game, char **av);
void	parsing(t_game *game, int ac, char **av);
void	read_map(t_game *game, char *file);
void	parsing_rgb(t_game *game, char *rgb, int *color);

void	handle_errors(t_game *game, int error, char *str);
void	check_error_name(t_game *game, char *av);
void	error_map(t_game *game, char *map);
void	holes_in_walls(t_game *game, char *map);
void	init_color_sprite(t_game *game);
void	init_player_pos(t_game *game);

#endif
