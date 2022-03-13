NAME = minitalk.a

SERVER = server

CLIENT = client

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_atoi.c\
		ft_printf.c

OBJECTS = $(SRC:.c=.o)

INCLUDES = minitalk.h

all: $(NAME) $(SERVER) $(CLIENT)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(SERVER): $(NAME)
	$(CC) $(CFLAGS) server.c $(NAME) -o server

$(CLIENT): $(NAME)
	$(CC) $(CFLAGS) client.c $(NAME) -o client

clean:
	rm -rf $(OBJECTS) $(OBJECTS2) server client

fclean: clean
	rm -rf $(NAME) 

re: fclean all 
