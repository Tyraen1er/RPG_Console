# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eferrand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 22:43:33 by eferrand          #+#    #+#              #
#    Updated: 2017/06/13 01:23:03 by eferrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# our executable name
NAME			:=	rpg

# base dirs
SRC_DIR			:=	./srcs
INC_DIR			:=	./includes
LIB_DIR			:=	./libs
OBJ_DIR			:=	./objs

# files to compile
FILE_LIST		:=	jeu_0.2.c

OBJ_FILES		:= $(addprefix $(OBJ_DIR)/,$(FILE_LIST:.c=.o))

# libraries
LIB_FT			:=	$(LIB_DIR)/libft
LIB_FT_INC		:=	-I $(LIB_FT)/includes/
LIB_FT_LINK		:=	-L $(LIB_FT) -l ft

# our project
INCLUDES		:=	$(LIB_FT_INC) -I$(INC_DIR)
LINK			:=	$(LIB_FT_LINK)

# compiler and flags
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror -fsanitize=address

all: obj libs $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

libs:
	@make -C $(LIB_FT)

# linking rule: executable NAME needs OBJ_FILES to link
$(NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LINK) -o $(NAME)

# compiler rule: each .o file in OBJ_DIR needs a .c file in SRC_DIR
# $< -- input file (.c)
# $@ -- output file (.o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

relibs:
	@make -C $(LIB_FT) re
	@make re --no-print-directory

re: fclean all
