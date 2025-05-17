CLIENT = client
SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
 
LIBFT = includes/libft/libft.a
SRCS_CLIENT = src/client.c 
SRCS_SERVER = src/server.c 
OBJS_CLIENT = src/client.o
OBJS_SERVER = src/server.o

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C includes/libft

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(SERVER)

src/client.o: src/client.c
	$(CC) $(CFLAGS) -c $< -o $@
src/server.o: src/server.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C includes/libft clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re