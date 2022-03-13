NAME = minitalk.a

SERVER = server_bonus

CLIENT = client_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_atoi.c\
		ft_printf.c

OBJECTS = $(SRC:.c=.o)

INCLUDES = minitalk.h

bonus : all
 
all: $(NAME) $(SERVER) $(CLIENT)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(SERVER): $(NAME)
	$(CC) $(CFLAGS) server_bonus.c $(NAME) -o server_bonus

$(CLIENT): $(NAME)
	$(CC) $(CFLAGS) client_bonus.c $(NAME) -o client_bonus

clean:
	rm -rf $(OBJECTS) $(OBJECTS2) server_bonus client_bonus

fclean: clean
	rm -rf $(NAME) 

re: fclean all 
