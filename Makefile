NAME =			so_long
BONUS =			bonus
CC =			gcc
AR =			ar rcs
CFLAGS =		-Wall -Wextra -Werror -g $(INCLUDES)
INCLUDES =		-I ./src/utils/headers -I $(LIBFT_DIR) -I /usr/include/c++/11 -I /usr/include/x86_64-linux-gnu/c++/11
LIBFT_DIR =		src/utils/libft
LIBFT =			$(LIBFT_DIR)/libft.a

SRCS =			src/checkers/map_checker.c \
				# src/checkers/player_checker.c \

SRC =			src/so_long.c \

BONUS_SRC =		

OBJS =			$(SRCS:.c=.o) $(SRC:.c=.o)

BONUS_OBJ =		$(BONUS_SRC:.c=.o) $(SRCS:.c=.o)

all:			$(NAME) $(BONUS)

$(NAME):		$(OBJS) $(LIBFT)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(BONUS):		$(BONUS_OBJ) $(LIBFT)
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
