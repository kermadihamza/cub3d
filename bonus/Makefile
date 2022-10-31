# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:01:45 by hakermad          #+#    #+#              #
#    Updated: 2022/10/31 15:15:40 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		parsing/handle_errors.c\
		parsing/parsing.c\
		parsing/parsing_rgb.c\
		parsing/read_sort_map.c\
		parsing/error_map.c\
		parsing/error_walls.c\
		init/init_player_pos.c\
		init/init_evil.c\
		init/init_door.c\
		init/sprite_factory.c\
		init/sprite_factory_utils.c\
		init/init_ray_values.c\
		utils/pos.c\
		utils/utils.c\
		utils/orientation.c\
		utils/size_map.c\
		utils/utils_display.c\
		utils/libft.c\
		utils/ft_atoi.c\
		utils/ft_split.c\
		utils/bloc_transfer.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		action/action.c\
		action/attack.c\
		action/animation.c\
		action/key.c\
		action/move.c\
		display/ft_mlx_pixel_put.c\
		display/minimap.c\
		display/display.c\
		display/display_one_img.c\
		display/raycasting.c\
		display/print_ray.c\
		display/sprite_3d.c\
		display/display_evil.c\
		display/display_player.c\
		display/door.c\
		display/numbers.c\
		display/messages.c\
		display/thread.c\
		utils/debug.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes #-fsanitize=thread

MLX = /usr/local/lib/
FRAMEWORK = -framework OpenGL -framework AppKit

NAME = cub3d

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(MLX) -lmlx $(FRAMEWORK)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re