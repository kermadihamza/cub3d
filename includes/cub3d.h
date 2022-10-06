/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:21:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/06 17:38:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "game.h"
# include "parsing.h"
# include "get_next_line.h"
# include "utils.h"
# include "display.h"

# define WIN_H 1024
# define WIN_W 1536
# define MINI_H 140
# define MINI_W 240
# define MINI_SIDE 10
# define TILE_SIZE 10
# define SPRITE_SIZE 64

# define PINK 0xeeccff
# define YELLOW 0xffe6b3
# define WHITE 0xffffff
# define PURPLE 0x4d4dff
# define RED 0xff0000

#endif
