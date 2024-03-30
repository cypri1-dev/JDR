# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 15:12:39 by cyprien           #+#    #+#              #
#    Updated: 2024/03/30 15:55:52 by cyprien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = story
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g3

BOLD    = \e[1m
FADE    = \e[2m
ITA     = \e[3m
BLINK   = \e[5m
GREEN   = \e[38;5;76m
RED     = \e[38;5;196m
YELLOW  = \e[38;5;227m
ORANGE  = \e[38;5;208m
PURPLE  = \e[38;5;201m
LBLUE   = \e[38;5;45m
BLUE    = \e[38;5;27m
INDI    = \e[38;5;91m
SPINK   = \e[38;5;225m
PEACH   = \e[38;5;223m
GREY    = \e[38;5;254m
RESET   = \e[00m

SOURCE = ./sources/
INIT = character.c init_story.c menu.c rules.c
GAME = $(addprefix $(SOURCE), $(INIT))

SRC = $(GAME)
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(RM) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re