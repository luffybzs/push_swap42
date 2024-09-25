# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:36:14 by ayarab            #+#    #+#              #
#    Updated: 2024/09/25 14:55:02 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	fonction.c fonction1.c ft_check.c ft_cost_algo.c \
		ft_parsing.c ft_pivot.c ft_small_sort.c ft_sort_stack.c \
		push_swap.c push.c reverse_rotate.c rotate.c stack.c swap.c \
		turkish.c \
		 
					
LIBFT_DIR       = libft/
LIBFT			= $(LIBFT_DIR)libft.a
OBJS			= $(SRCS:.c=.o)

CC				= cc -g3
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap


all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
clean:
				$(RM) $(OBJS)
				make clean -sC $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME)
				make fclean -sC $(LIBFT_DIR)

re:				fclean $(NAME)

$(LIBFT): 			
				make -sC $(LIBFT_DIR)

%.o : %c
				$(CC) $(CFLAGS) -c $< -o $@
				
  
.PHONY:			all clean fclean re bonus