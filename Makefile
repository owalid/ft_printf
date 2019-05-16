# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-ayad <oel-ayad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 20:29:21 by oel-ayad          #+#    #+#              #
#    Updated: 2019/05/16 10:10:42 by oel-ayad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=  libftprintf.a

SRC		=  	ft_print.c \
			ft_printf.c \
			ft_options.c \
			ft_init.c \
			ft_utils.c \
			ft_utils_df.c \
			ft_formater_sc.c \
			ft_formater_df.c \
			ft_formater_xx.c \
			ft_formater_p.c \
			ft_formater_u.c \
			ft_formater_o.c \
			ft_utils_o.c \
			ft_utils_p.c \
			ft_parser.c \
			ft_prepare.c \
			ft_operations_idscpo.c \
			ft_operations_uxf.c \
			ft_error.c \


OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= libft/

SRCDIR	= srcs/
INCDIR	= includes/
OBJDIR	= objs/

CC		= @gcc
CFLAGS	= -I $(INCDIR) -I $(FT_INC) -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c $(INCDIR)/ft_printf.h $(INCDIR)/ft_opprintf.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	@make -C $(FT_INC)
	cp $(FT_INC)libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)
	@make -C $(FT_INC) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(FT_INC) fclean

re: fclean all

.PHONY: all obj fclean clean re
