#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 17:25:42 by jbrisset          #+#    #+#              #
#    Updated: 2019/04/16 17:25:46 by jbrisset         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	push_swap
CHCKR		= 	checker
HEADER		=	push_swap.h
SRC_SWAP	=	stack_manager.c\
				aux_functions.c\
				operations.c\
				stack_a_handler.c\
				stack_b_handler.c\
				verifications.c\
				push_swap.c\

SRC_CHCKR	=	stack_manager.c\
				operations.c\
				checker.c\
				verifications.c\

OBJ_SWAP	=	$(SRC_SWAP:%.c=%.o)
OBJ_CHCKER	=	$(SRC_CHCKR:%.c=%.o)

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_SWAP) $(OBJ_CHCKER)
		cd libft && make
		gcc $(FLAGS) -I $(HEADER) $(OBJ_SWAP) -L. libft/libftprintf.a -o $(NAME)
		gcc $(FLAGS) -I $(HEADER) $(OBJ_CHCKER) -L. libft/libftprintf.a -o $(CHCKR)

%.o:%.c
	gcc $(FLAGS) -c -o $@ $<

clean:	
		cd libft/ && make clean
		rm -rf $(OBJ_SWAP) $(OBJ_CHCKER)

fclean:	clean
		cd libft/ && make fclean
		rm -rf $(NAME) $(CHCKR)

re: fclean all

norme:
	norminette $(SRC_SWAP) $(SRC_CHCKR) $(HEADER)