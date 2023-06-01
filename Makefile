CFLAGS  = -Wall -Wextra -Werror

CLIENT = client

SERVER = server

LIBFT = libft/libft.a

INC = -I libft/includes

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(CLIENT) srcs/client.c $(LIBFT)

$(SERVER): $(LIBFT)
	@gcc $(CFLAGS) $(INC) -o $(SERVER) srcs/server.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo 🔥 🔥 Making Executables ✅ ✅

clean:
	@make -C libft clean
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER)
	@echo  🔥 🔥 Deleting executables files 🗑️ 🗑️

re: fclean all

.PHONY: all clean fclean re