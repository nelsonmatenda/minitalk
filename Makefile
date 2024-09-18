NAME 	=	client server
LIB		=	./lib/libftprintf.a
LIB_DIR =	./lib
DIR_OBJS = ./obj/

CC = cc
FLAG 	=	-Wall -Wextra -Werror

all: $(NAME)

% : %.c $(LIB)
		@$(CC) $(FLAG) $< $(LIB) -o $(DIR_OBJ)$@
		@echo "Minitalk compiled"

$(LIB): $(LIB_DIR)
		@make -C $(LIB_DIR)

$(DIR_OBJS):
		@mkdir -p $(DIR_OBJ)

clean:
		@rm -rf $(DIR_OBJ)
		@make fclean -C $(LIB_DIR)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
