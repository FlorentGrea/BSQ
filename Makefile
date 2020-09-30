# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrea <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 10:31:33 by fgrea             #+#    #+#              #
#    Updated: 2020/09/30 20:54:55 by fgrea            ###   ########lyon.fr    #
#    Updated: 2020/09/30 19:08:13 by lgrandje         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
C_FLAGS = -Wall -Wextra -Werror

OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = 
SRC_NAME = main.c ft_stocking_first_line.c \
		   ft_check_first_line.c ft_putstr.c ft_strlen.c ft_map_error.c \
		   ft_read_input.c ft_treat_input.c ft_set_data.c \
		   ft_stocking_map_lines.c ft_check_map_lines.c ft_strcat.c \
		   ft_find_sqr.c ft_show_completed_map.c ft_alloc_sqr.c \
		   ft_set_algo.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
						@$(CC) $(C_FLAGS) $(INC) $(OBJ) -o $@
						@echo "Obj folder & files created"
						@echo "Executable created"
						@echo "Compilation finished"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
						@mkdir $(OBJ_PATH) 2> /dev/null || true
						@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
						@rm -rf $(OBJ_PATH)	2> /dev/null || true
						@echo "Obj folder & files suppressed"

fclean: clean
						@rm -f $(NAME)
						@echo "Executable suppressed"

re: fclean
						@$(MAKE) all

norme:
						@norminette -R CheckForbiddenSourceHeader $(SRC)
						@echo "C files norme check finished"
						@norminette -R CheckDefine $(INC_PATH)
						@echo "Header files norme check finished"
