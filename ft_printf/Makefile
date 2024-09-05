# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 11:17:27 by ayarab            #+#    #+#              #
#    Updated: 2024/06/13 10:09:57 by ayarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_base_printf.c ft_printf_str.c ft_printf.c ft_ptr_printf.c \
					
					
OBJS			= $(SRCS:.c=.o)

CC				= cc -c
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re