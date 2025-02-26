CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDE_PRINTF = $(PRINTF_DIR)/includes
INCLUDE = includes

PATH_SRCS = srcs
HEADER = $(INCLUDE)/push_swap.h

SRCS = $(addprefix $(PATH_SRCS)/, ft_swap.c pile_depile.c ft_push.c ft_rotate.c \
		ft_reverse_rotate.c push_swap.c ft_split.c main.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PATH_SRCS)/%.o: $(PATH_SRCS)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -I$(INCLUDE_PRINTF) -c $< -o $@

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDE) -I$(INCLUDE_PRINTF) -L$(PRINTF_DIR) -lftprintf
	@echo "push_swap compilation done."

$(PRINTF):
	@make -C $(PRINTF_DIR) --no-print-directory
	@echo "ft_printf compilation done."

clean:
	@rm -rf $(OBJS)
	@make -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	@rm -rf $(NAME)
	@make -C $(PRINTF_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
