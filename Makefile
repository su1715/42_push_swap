# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujpark <sujpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 22:34:23 by sujpark           #+#    #+#              #
#    Updated: 2022/07/16 17:18:19 by sujpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
NAME			=	push_swap
BONUS			=	checker

SRCS			=	push_swap.c \
					init.c \
					input.c \
					swap.c \
					pop_push.c \
					rotate.c \
					rotate_reverse.c \
					sort_small.c \
					sort_large.c \
					utils.c \
					finish.c
INCS			=	push_swap.h
OBJ_DIR			=	./obj
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_SRCS		=	checker.c \
					init.c \
					input.c \
					swap.c \
					pop_push.c \
					rotate.c \
					rotate_reverse.c \
					utils.c \
					get_next_line.c \
					finish.c
BONUS_INCS		=	checker.h
BONUS_OBJS		=	$(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

LIBFT_DIR		=	./libft
LIBFT_NAME		=	ft
LIBFT			=	$(LIBFT_DIR)/lib$(LIBFT_NAME).a

all				:	$(NAME)

bonus			:	$(BONUS)

$(NAME)			:	$(LIBFT) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@

$(BONUS)		:	$(LIBFT) $(BONUS_OBJS) $(BONUS_INCS)
	$(CC) $(CFLAGS) -I ./ $(BONUS_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@

$(OBJ_DIR)/%.o	:	%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

$(LIBFT)		:
	make -C $(LIBFT_DIR) all

clean			:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean			:	clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	make -C $(LIBFT_DIR) fclean

re				:
	make fclean
	make all

.PHONY			:	all clean fclean re bonus
