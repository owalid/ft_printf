# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 20:29:21 by oel-ayad          #+#    #+#              #
#    Updated: 2019/04/30 13:34:14 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a

SRC		=  	ft_print.c \
			ft_printf.c \
			ft_operations.c \
			options.c \
			ft_get_type.c \
			clean.c \
			formater_df.c \
			formater_sc.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))


FT		= libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= libft/

SRCDIR	= srcs/
INCDIR	= includes/
OBJDIR	= objs/

CC		= gcc
CFLAGS	= -I $(INCDIR) -I $(FT_INC) -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCDIR)/ft_printf.h $(INCDIR)/ft_opprintf.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	make -C $(FT)
	cp $(FT_INC)libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: all obj fclean clean re
