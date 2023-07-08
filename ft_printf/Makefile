# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 07:17:16 by pbalbino          #+#    #+#              #
#    Updated: 2023/02/14 07:21:59 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
RM		= /bin/rm -f

SRCS	= 	ft_char.c \
			ft_digit.c \
			ft_lowerhexa.c \
			ft_pointer.c \
			ft_printf.c \
			ft_string.c \
			ft_unsignedint.c \
			ft_upperhexa.c 
			

OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			
.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			
clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re