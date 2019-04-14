# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 16:42:45 by dbolilyi          #+#    #+#              #
#    Updated: 2019/04/14 21:31:19 by dbolilyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC =	src/FtGkrellm.class.cpp \
		src/GraficDisplay.class.cpp \
		src/AMonitorDisplay.cpp \
		src/AMonitorModule.cpp \
		src/NcurDisplay.class.cpp \
		src/main.cpp \
		src/modules/HostUserModule.cpp \
		src/modules/CPUModule.cpp \
		src/modules/DateTimeModule.cpp \
		src/modules/OSInfoModule.cpp \
		src/modules/RAMModule.cpp \
		src/modules/NetworkModule.cpp \
		src/modules/ProcessesModule.cpp \
		src/modules/StorageModule.cpp \
		src/modules/DisksModule.cpp

OBJ = $(SRC:.cpp=.o)

INC =	-I inc/ \
		-I inc/modules \
		-I./frameworks/SDL2.framework/Headers \
		-I./frameworks/SDL2_ttf.framework/Headers

ERRFL = -Wall -Wextra -g -std=c++98 -Werror

FL =	-F./frameworks \
		-rpath ./frameworks \
		-framework SDL2 -framework SDL2_ttf -lncurses

all: $(NAME)

$(OBJ): %.o: %.cpp
	@echo "\033[93mCompiling \033[0m$<"
	@clang++ $(ERRFL) -c -o $@ $< $(INC)

$(NAME): $(OBJ)
	@echo "\033[93mCompiling $(NAME)\033[0m"
	@clang++ $(ERRFL) $(FL) -o $@ $(OBJ)
	@echo "\033[92mDONE\033[0m"
	

clean:
	@echo "\033[91mDeleting $(NAME) objects\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[91mDeleting $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean \
	all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
