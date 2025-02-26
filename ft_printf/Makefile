CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a

PATH_SRCS = srcs
HEADER = includes/libftprintf.h

SRCS = $(addprefix $(PATH_SRCS)/, ft_putchar.c ft_putstr.c ft_putnbr.c \
		ft_putnbr_unsigned.c ft_putnbr_base.c ft_print_adress.c ft_printf.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

.c.o:
	@$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re