# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 20:44:16 by davidga2          #+#    #+#              #
#    Updated: 2023/07/29 06:21:56 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = src/push_swap.c	\
	  src/few_values.c	\
	  src/ft_rra.c		\
	  src/ft_swap.c		
#	  src/ft_pa.c			\
#	  src/ft_pb.c			\

OBJS = $(SRC:%.c=%.o)

CC = cc -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(SRC) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
