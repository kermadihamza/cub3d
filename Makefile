# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:01:45 by hakermad          #+#    #+#              #
#    Updated: 2022/09/12 17:10:38 by hakermad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		parsing/handle_errors.c\
		parsing/parsing.c\
		parsing/init_map.c\
		parsing/error_file.c\
		parsing/error_map.c\
		parsing/error_walls.c\
		utils/libft.c\
		utils/utils.c\
		utils/ft_atoi.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		utils/ft_split.c\
		utils/debug.c\
		display/display.c\
		display/ft_mlx_pixel_put.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes

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