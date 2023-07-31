# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbalbino <pbalbino@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 11:49:56 by pbalbino          #+#    #+#              #
#    Updated: 2023/07/30 19:16:00 by pbalbino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FLAGS = -Wall -Wextra -Werror
PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF = -l ftprintf
INCLUDES = -I./ft_printf
LIBRARIES = -L./ft_printf

SERVER = server
SERVER_SRC = server.c \
			utils.c

CLIENT = client
CLIENT_SRC = client.c \
			utils.c

all : $(SERVER) $(CLIENT)

$(SERVER) : $(PRINTF)
	cc $(C_FLAGS) $(SERVER_SRC) $(INCLUDES) $(LIBRARIES) $(FT_PRINTF) -o $(SERVER)

$(CLIENT) : $(PRINTF)
	cc $(C_FLAGS) $(CLIENT_SRC) $(INCLUDES) $(LIBRARIES) $(FT_PRINTF) -o $(CLIENT)


$(PRINTF):
	make -sC ft_printf

clean:
	make clean -sC ft_printf
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -sC ft_printf
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
