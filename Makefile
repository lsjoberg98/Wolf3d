# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsjoberg <lsjoberg@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 15:56:04 by lsjoberg           #+#    #+#              #
#    Updated: 2020/10/28 14:57:29 by lsjoberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = wolf3d

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g

# Folders
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx/

# Source files and object files
SRC_FILES = main.c draw_map.c read_map.c set_hooks.c set_movement.c \
	set_texture.c init_settings.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX = $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
		-Ofast -lmlx -framework OpenGL -framework AppKit

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@clear
	@echo "*:・ﾟ✧*:・ﾟ✧ Compiling.   *:・✧*:・✧"
	@sleep 0.5
	@clear
	@echo "*:・ﾟ✧*:・ﾟ✧ Compiling..  *:・✧*:・✧"
	@sleep 0.5
	@clear
	@echo "*:・ﾟ✧*:・ﾟ✧ Compiling... *:・✧*:・✧"
	@sleep 0.5
	@clear
	@echo "*:・ﾟ✧*:・ﾟ✧ Compiling..  *:・✧*:・✧"
	@sleep 0.5
	@clear
	@echo "*:・ﾟ✧*:・ﾟ✧ Compiling.   *:・✧*:・✧"
	@sleep 0.5
	@clear
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "*:・ﾟ✧*: $(NAME) generated *:・✧*:・✧"
	@sleep 1
	@echo 
	@echo "Usage: ./wolf3d "

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINLBX_DIR) clean
	@echo " Objects removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo " $(NAME) removed! "

# re rule
re: fclean all

# time for a coffee break
coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 2.5
	@clear

# phony
.PHONY: all clean fclean re
