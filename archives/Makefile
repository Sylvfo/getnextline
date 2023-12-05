# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 09:31:55 by marvin            #+#    #+#              #
#    Updated: 2023/12/05 09:31:55 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c	get_next_line_utils.c

NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files.c>
RM = rm -f

OBJ := $(SRCS..c=.o)

all: $(NAME)

$(NAME):	$(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY:	all re clean fclean bin