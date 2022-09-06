/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:21:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/06 12:03:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*map;
}	t_game;

# include "parsing.h"
# include "get_next_line.h"
# include "utils.h"


#endif
