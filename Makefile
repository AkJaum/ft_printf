NAME		= libftprintf.a
TESTER		= ft_printf_tester

SRC			= ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c ft_puthex.c ft_putpointer.c
TESTER_SRC	= ft_printf_tester.c

OBJ			= $(SRC:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(TESTER)

re: fclean all

m:
	@if [ ! -f $(NAME) ]; then \
		echo "Não existe um arquivo de printf.a, rode primeiro (make re) e depois (make m)"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) $(TESTER_SRC) -L. -lftprintf -o $(TESTER)
	./$(TESTER)

.PHONY: all clean fclean re m