NAME	:= minitalk
CFLAGS	:= -Wextra -Wall -Werror
LIBFT	:= ./lib/Libft
MINITALK:= ./lib/Minitalk

HEADERS	:= -I $(LIBFT) -I $(MINITALK)
LIBS	:= $(LIBFT)/libft.a
SRCS_1	:=  ./src/server.c 
SRCS_2	:=	./src/client.c 
OBJS_1	:= ${SRCS_1:.c=.o}
OBJS_2	:= ${SRCS_2:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) "

$(NAME): server client

server: $(OBJS_1)
	@$(CC) $(OBJS_1) $(LIBS) $(HEADERS) -o server

client: $(OBJS_2)
	@$(CC) $(OBJS_2) $(LIBS) $(HEADERS) -o client

clean:
	@rm -f $(OBJS_1) $(OBJS_2)
	@make -C ./lib/Libft clean

fclean: clean
	@rm -f server client
	@make -C ./lib/Libft fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft, server, client
