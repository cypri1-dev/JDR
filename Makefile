# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 15:12:39 by cyprien           #+#    #+#              #
#    Updated: 2024/08/30 12:12:30 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = story
CC = cc
RM = rm -rf
CFLAGS = -Wextra -Werror -g3

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

SOURCE = sources
INIT = $(wildcard $(SOURCE)/init/*.c)
FIGHT = $(wildcard $(SOURCE)/fight/*.c)
MENU = $(wildcard $(SOURCE)/menu/*.c)

OBJDIR = obj
INIT_DIR = $(OBJDIR)/init
MENU_DIR = $(OBJDIR)/menu
FIGHT_DIR = $(OBJDIR)/fight

OBJDIRS := $(OBJDIR) $(INIT_DIR) $(MENU_DIR) $(FIGHT_DIR)

SRC = $(INIT) $(FIGHT) $(MENU)

OBJ_INIT = $(INIT:sources/%.c=obj/%.o)
OBJ_FIGHT = $(FIGHT:sources/%.c=obj/%.o)
OBJ_MENU = $(MENU:sources/%.c=obj/%.o)
OBJS = $(OBJ_INIT) $(OBJ_MENU) $(OBJ_FIGHT)

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	@echo "$(BOLD)Linking...$(RESET)"
	$(RM) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

$(OBJDIR)/%.o: $(SOURCE)/%.c
	@echo "$(BOLD)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$@ compiled successfully!$(RESET)"

$(OBJDIRS):
	mkdir -p $(OBJDIRS)

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
