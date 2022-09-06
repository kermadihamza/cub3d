/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:12:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 16:06:54 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define NB_ARGUMENTS 1
# define MALLOC_F 2
# define WRONG_NAME 3
# define MLX_INIT 4
# define UNEXIST_MAP 5
# define INCORR_CHAR 6

# include "game.h"

void	init_map(t_game *game, char **av);

void	handle_errors(int error, char *str);
void	check_error_name(char *av);

#endif
