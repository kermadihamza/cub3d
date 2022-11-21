# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:01:45 by hakermad          #+#    #+#              #
#    Updated: 2022/11/21 17:41:13 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		parsing/handle_errors.c\
		parsing/parsing.c\
		parsing/parsing_rgb.c\
		parsing/read_sort_map.c\
		parsing/init_player_pos.c\
		parsing/error_map.c\
		parsing/error_walls.c\
		utils/pos.c\
		utils/utils.c\
		utils/utils_raycasting.c\
		utils/utils_display.c\
		utils/libft.c\
		utils/ft_atoi.c\
		utils/ft_split.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		display/key_manager.c\
		display/ft_mlx_pixel_put.c\
		display/init_color_sprite.c\
		display/minimap.c\
		display/display.c\
		display/raycasting.c\
		display/init_ray_values.c\
		display/print_ray.c\
		display/sprite_3d.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes -O3 #-fsanitize=address

MLX_DIR = ../mlx/
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

all: $(NAME)

$(NAME):	$(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re