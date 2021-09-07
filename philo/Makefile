NAME=philo_one

CC=gcc
FLAGS=-Wall -Wextra -Werror #-lpthread

SRC_DIR=./srcs
OBJ_DIR=./obj
HEADER_DIR = ./incs
HEADER_NAME =	ph_main.h \
				ph_funcs.h \
				ph_structs.h
SRC_NAME =		funcs/ph_print.c \
				funcs/ph_malloc.c \
				ph_main.c \
				ph_exit.c \
				ph_struct_add.c \
				ph_struct_remove.c

SRC = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))
HEADER = $(addprefix $(HEADER_DIR)/, $(HEADER_NAME))
OBJ = $(SRC)
INC = -I ./incs

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(SRC) $(INC) $(FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p obj
	@mkdir -p obj/funcs
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re