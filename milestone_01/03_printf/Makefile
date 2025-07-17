NAME := libftprintf.a

CC := cc
#-fsanitize=address -g
CFLAGS := -Wall -Wextra -Werror

SRC := ft_printf.c ft_memhex.c ft_putcss.c ft_putnbr.c

OBJ := $(SRC:%.c=%.o)

HEADER := ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY := all clean fclean re