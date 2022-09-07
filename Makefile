# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 17:01:45 by hakermad          #+#    #+#              #
#    Updated: 2022/09/07 10:36:21 by lrondia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c\
		parsing/handle_errors.c\
		parsing/parsing.c\
		parsing/init_map.c\
		parsing/error_name.c\
		parsing/error_map.c\
		parsing/error_walls.c\
		utils/libft.c\
		utils/utils.c\
		utils/gnl/get_next_line.c\
		utils/gnl/get_next_line_utils.c\
		utils/ft_split.c\
		utils/debug.c\

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