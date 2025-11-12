NAME		= libftprintf.a

SRC_DIR		= srcs
INC_DIR		= include

SRC			= ft_printf.c \
			  ft_putchar.c \
			  ft_putstr.c \
			  ft_putnbr.c \
			  ft_putunsigned.c \
			  ft_puthex.c \
			  ft_putpointer.c

OBJ			= $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I $(INC_DIR)
AR			= ar rcs
RM			= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) libft.a

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

main:
	$(CC) main.c $(NAME) libft.a -I $(INC_DIR) -o test_printf

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re