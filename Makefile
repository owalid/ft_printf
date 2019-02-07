# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 20:29:21 by oel-ayad          #+#    #+#              #
#    Updated: 2019/02/07 12:41:41 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a

SRC		= \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	mkdir - p $(OBJDIR)
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $< -I $(INCDIR)

$(NAME): $(OBJ)
	make -C $(FT)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all obj fclean clean re
