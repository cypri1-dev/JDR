# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 15:12:39 by cyprien           #+#    #+#              #
#    Updated: 2024/08/25 19:09:20 by cyprien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = story
CC = cc
RM = rm -rf
CFLAGS = -Wextra -Werror -g3
OBJDIR = obj

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
FIGHT = fight.c tests_fight.c
GAME = $(addprefix $(SOURCE), $(INIT) $(FIGHT))

SRC = $(GAME)
OBJS = $(patsubst $(SOURCE)%.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "$(BOLD)Linking...$(RESET)"
	$(RM) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SOURCE)%.c
	@echo "$(BOLD)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$@ compiled successfully!$(RESET)"

clean:
	@echo "$(BOLD)Cleaning object files...$(RESET)"
	$(RM) $(OBJDIR)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(BOLD)Cleaning executable...$(RESET)"
	$(RM) $(NAME)
	@echo "$(GREEN)Executable cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
