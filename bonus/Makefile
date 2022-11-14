# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:01:45 by hakermad          #+#    #+#              #
#    Updated: 2022/11/14 17:33:16 by hakermad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		parsing/handle_errors.c\
		parsing/parsing.c\
		parsing/parsing_rgb.c\
		parsing/read_sort_map.c\
		parsing/error_map.c\
		parsing/error_walls.c\
		init/initialization.c\
		init/init_player_pos.c\
		init/init_evil.c\
		init/init_door.c\
		init/sprite_factory.c\
		init/sprite_factory_utils.c\
		init/init_ray_values.c\
		action/action.c\
		action/attack.c\
		action/animation.c\
		action/key.c\
		action/move.c\
		display/display.c\
		display/display_floor_roof.c\
		display/thread.c\
		display/raycasting/raycasting.c\
		display/raycasting/print_ray.c\
		display/sprite/sprite_3d.c\
		display/sprite/display_evil.c\
		display/sprite/evil_time.c\
		display/sprite/display_player.c\
		display/sprite/door.c\
		display/sprite/numbers.c\
		display/sprite/messages.c\
		display/sprite/display_one_img.c\
		display/minimap.c\
		utils/pos.c\
		utils/utils.c\
		utils/orientation.c\
		utils/size_map.c\
		utils/utils_display.c\
		utils/libft.c\
		utils/ft_atoi.c\
		utils/ft_split.c\
		utils/bloc_transfer.c\
		utils/ft_mlx_pixel_put.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		utils/debug.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes -O3 #-fsanitize=thread

MLX = /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

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