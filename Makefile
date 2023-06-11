CFLAGS  = -Wall -Wextra -Werror

CLIENT = client

SERVER = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

NAME = $(CLIENT)

LIBFT = libft/libft.a

INC = -I libft/includes

all: $(CLIENT) $(SERVER)

$(NAME): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(CLIENT) srcs/$(NAME).c $(LIBFT)

$(SERVER): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(SERVER) srcs/server.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo Making lib

$(CLIENT_BONUS): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(CLIENT_BONUS) srcs/client_bonus.c $(LIBFT)

$(SERVER_BONUS): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(SERVER_BONUS) srcs/server_bonus.c $(LIBFT)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	@make -C libft clean
	@echo Deleting .o Files

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo  Deleting executable files

re: fclean all

.PHONY: all clean fclean re