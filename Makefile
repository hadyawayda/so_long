NAME =			so_long
BONUS =			bonus
CC =			gcc
AR =			ar rcs
CFLAGS =		-Wall -Wextra -Werror -g $(INCLUDES)
INCLUDES=		-I ./src/utils/headers -I /usr/include/c++/11 -I /usr/include/x86_64-linux-gnu/c++/11 -L /usr/lib/gcc/x86_64-linux-gnu/11
LIBFT_DIR =		src/utils/libft
LIBFT =			$(LIBFT_DIR)/libft.a

SRCS =			src/commands/push_commands.c \
				src/commands/reverse_commands.c \
				src/commands/rotate_commands.c \
				src/commands/swap_commands.c \
				src/errors/errors.c \
				src/helpers/atoi_modified.c \
				src/helpers/check_duplicates.c \
				src/helpers/check_sorted.c \
				src/helpers/free.c \
				src/helpers/stack_traversal.c \
				src/helpers/sort.c \
				src/processors/algorithm.c \
				src/processors/calculations.c \
				src/processors/pre_process.c \
				src/processors/process.c \
				src/processors/rotate_stacks.c \
				src/processors/sort.c \
				src/processors/stack.c \

SRC =			src/push_swap.c

BONUS_SRC =		src/checker/checker.c \

OBJS =			$(SRCS:.c=.o) $(SRC:.c=.o)

BONUS_OBJ =		$(BONUS_SRC:.c=.o) $(SRCS:.c=.o)

all:			$(NAME) $(BONUS)

$(NAME):		$(OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS):		$(BONUS_OBJ) $(OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ) $(LIBFT)

$(LIBFT):
				@make --no-print-directory -C $(LIBFT_DIR)

%.o:			%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJS) $(BONUS_OBJ)
				@make --no-print-directory clean -C $(LIBFT_DIR)

fclean:			clean
				@rm -f $(NAME) $(BONUS)
				@make --no-print-directory fclean -C $(LIBFT_DIR)

re:				fclean all