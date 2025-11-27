# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 18:14:24 by marvin            #+#    #+#              #
#    Updated: 2025/11/23 18:14:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c
OBJS = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
