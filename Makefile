CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = push_swap

SRCS = push_swap.c \
		pop_push.c \
		input.c \
		rotate.c \
		rotate_reverse.c \
		swap.c \
		sort.c \
		utils.c \
		utils2.c
INCS = push_swap.h

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

$(LIBFT)	:
	make -C $(LIBFT_DIR) all

clean :
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re	:
	make fclean
	make all

.PHONY : all clean fclean re bonus
