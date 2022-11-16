/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:11:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/16 14:46:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define WIN_H 1080
# define WIN_W 1620
# define MINI_H 200
# define MINI_W 300
# define MINI_SIDE 10
# define TILE_SIZE 10
# define WALL_SIZE 640
# define BANNER_Y -238
# define ME_LIFE 8
# define EVIL_LIFE 5

# define N_THREAD 4

# define PINK 0xeeccff
# define YELLOW 0xffe6b3
# define WHITE 0xffffff
# define PURPLE 0x4d4dff
# define VIOLET 0xab92e0
# define RED 0xff0000
# define D_RED 0xc52a2a
# define GREEN 0x00ff00
# define BLACK 0x404040
# define ORANGE 0xffad4e
# define BLUE 0x6ec5ed

# define NOT_PIXEL 9961608
# define STILL_NOT_PIXEL -16777216

# ifdef LINUX
#  define SOUND_PATH "/usr/bin/aplay"
#  define SOUND_CMD "aplay"
# else
#  define SOUND_PATH "/usr/bin/afplay"
#  define SOUND_CMD "afplay"
# endif

# define SPEED 2

#endif
