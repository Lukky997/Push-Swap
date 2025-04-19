CC = cc -g
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INCLUDE_PRINTF = $(PRINTF_DIR)/includes
INCLUDE = includes

PATH_SRCS = srcs
PATH_CMDS = $(PATH_SRCS)/commands
HEADER = $(INCLUDE)/push_swap.h

SRCS = \
	$(PATH_CMDS)/ft_swap.c \
	$(PATH_CMDS)/ft_push.c \
	$(PATH_CMDS)/ft_rotate.c \
	$(PATH_CMDS)/ft_reverse_rotate.c \
	$(PATH_CMDS)/sort_three.c \
	$(PATH_SRCS)/pile_depile.c \
	$(PATH_SRCS)/push_swap.c \
	$(PATH_SRCS)/biggest_and_smallest.c \
	$(PATH_SRCS)/utils.c \
	$(PATH_SRCS)/target.c \
	$(PATH_SRCS)/cost.c \
	$(PATH_SRCS)/algo.c \
	$(PATH_SRCS)/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
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
