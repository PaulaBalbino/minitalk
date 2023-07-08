# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 11:49:56 by pbalbino          #+#    #+#              #
#    Updated: 2023/07/08 16:00:22 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

PRINTF_PATH	= ft_printf/
PRINTF_NAME	= libftprintf.a
PRINTF		= $(PRINTF_PATH)$(PRINTF_NAME)

INC			= 	-I ./ft_printf/ \
				-I ./code/

SRC_PATH	=	code/
SRC			=	client.c \
				message.c \
				utils.c
				
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(PRINTF) $(NAME_CLIENT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(PRINTF):
	@make -sC $(PRINTF_PATH)

$(NAME_CLIENT): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS) $(PRINTF) $(INC)

bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	@rm -f $(NAME_CLIENT)
	@rm -f $(PRINTF_PATH)$(PRINTF_NAME)

re: fclean all

.PHONY: all re clean fclean
