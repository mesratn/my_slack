CC =		gcc

RM =		rm -f

LIB =		cd libmy/; make

LIB_CLEAN =	cd libmy/; make clean

LIB_FCLEAN =	cd libmy/; make fclean

CFLAGS =	-Wall -Werror -W -Wextra

NAME_CLIENT =	client_bin

NAME_SERVER =   server_bin

SRCS_CLIENT =	$(wildcard client/*.c)

SRCS_SERVER =   $(wildcard server/functions/*.c)

OBJS_CLIENT =	$(SRCS_CLIENT:%.c=%.o)

OBJS_SERVER =   $(SRCS_SERVER:%.c=%.o)

all:		$(NAME_CLIENT)
		$(NAME_SERVER)

client:		$(NAME_CLIENT)

server:		$(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT)
		@$(LIB)
		@echo "-> Compilation client_bin ..."
		$(CC) $(OBJS_CLIENT) -L libmy/ -lmy $(CFLAGS) -o $(NAME_CLIENT) $(LDFLAGS)

$(NAME_SERVER): $(OBJS_SERVER)
		@$(LIB)
		@echo "-> Compilation server_bin ..."
		$(CC) $(OBJS_SERVER) -L libmy/ -lmy $(CFLAGS) -o $(NAME_SERVER) $(LDFLAGS)

clean_client:		
		@echo "-> clean client..."
		@$(RM) $(OBJS_CLIENT)
		@$(LIB_CLEAN)

fclean_client:		clean_client
		@echo "-> fclean client..."
		@$(RM) $(NAME_CLIENT)
		@$(LIB_FCLEAN)

clean_server:
		@echo "-> clean server..."
		@$(RM) $(OBJS_SERVER)
		@$(LIB_CLEAN)

fclean_server: 		clean_server
		@echo "-> fclean server..."
		@$(RM) $(NAME_SERVER)
		@$(LIB_FCLEAN)

re:		fclean all clean

.PHONY:		all clean fclean re
