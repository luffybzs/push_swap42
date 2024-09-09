# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 14:36:14 by ayarab            #+#    #+#              #
#    Updated: 2024/09/09 14:31:26 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_check.c fonctio.c push_swap.c lst_new.c stack.c ft_lstadd_back_stack.c \
					
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