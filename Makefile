# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsauvair <gsauvair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/02 15:59:12 by gsauvair          #+#    #+#              #
#    Updated: 2015/05/02 16:16:40 by gsauvair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

SRC = ./srcs/main.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

GLFW_DIR = ./glfw/

GLFW = ./glfw/src/libglfw3.a

GL_FLAG = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LIB_DIR); $(MAKE) -f Makefile
	@git submodule init
	@git submodule update
	@cd $(GLFW_DIR); cmake CMakeLists.txt; $(MAKE) -f Makefile
	@gcc $(FLAG) -o $(NAME) $(OBJ) $(LIB_DIR)libft.a $(GLFW) $(GL_FLAG)
	
clean:
	@$(DEL) $(OBJ)
	@cd $(LIB_DIR); $(MAKE) clean -f Makefile

fclean: clean
	@$(DEL) $(NAME)
	@cd $(LIB_DIR); $(MAKE) fclean -f Makefile

re: fclean all
