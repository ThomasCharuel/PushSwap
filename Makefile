# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcharuel <tcharuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 13:33:40 by tcharuel          #+#    #+#              #
#    Updated: 2023/12/04 12:10:27 by tcharuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SOURCES = main.c parse_args.c parsing_constraints.c stack_utils.c stack_display.c \
			algorithm.c algorithm_2.c moves.c move_analysis.c

SOURCES_BONUS = main_bonus.c stack_utils.c parse_args.c parsing_constraints.c \
			algorithm.c algorithm_2.c moves.c move_analysis.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) -L$(LIBFT_DIR) -lft

bonus: $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(SOURCES_BONUS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(NAME) bonus all clean fclean re
