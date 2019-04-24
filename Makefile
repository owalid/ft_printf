# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 20:29:21 by oel-ayad          #+#    #+#              #
#    Updated: 2019/02/08 14:15:25 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a

SRC		=  ft_print.c \
		   ft_printf.c \
		   ft_operations.c \
		   options.c \
		   conf_output.c \
		   ft_get_type.c \

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

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCDIR)/ft_printf.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(FT_INC) -o $@ -c $< -I $(INCDIR)

$(NAME): $(OBJ)
	make -C $(FT)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all obj fclean clean re
