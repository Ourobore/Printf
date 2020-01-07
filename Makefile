# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:57:14 by lchapren          #+#    #+#              #
#    Updated: 2020/01/07 10:06:28 by lchapren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RLIBFT		=	./libft-src

LSRCS		=	$(RLIBFT)/ft_substr.c $(RLIBFT)/ft_calloc.c \
				$(RLIBFT)/ft_bzero.c $(RLIBFT)/ft_putchar_fd.c \
				$(RLIBFT)/ft_atoi.c $(RLIBFT)/ft_strlen.c

RSRCS		=	./src

SRCS		=	$(RSRCS)/ft_printf.c $(RSRCS)/ft_parse.c \
				$(RSRCS)/ft_convert.c $(RSRCS)/ft_struc.c \
				$(RSRCS)/ft_utils.c $(RSRCS)/ft_percent.c \
				$(RSRCS)/ft_char.c $(RSRCS)/ft_string.c \
				$(RSRCS)/ft_pointer.c $(RSRCS)/ft_integer.c \
				$(RSRCS)/ft_u_integer.c $(RSRCS)/ft_unsigned.c

INCLUDES	=	-I$(RSRCS)/ft_printf.h

LOBJS		:=	${LSRCS:.c=.o}

OBJS		:=	${SRCS:.c=.o}

NAME		=	libftprintf.a

FLAGS		=	-Wall -Werror -Wextra

.c.o		:
				gcc $(FLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LOBJS)
				ar -rcs $(NAME) $(OBJS) $(LOBJS)

clean		:	
				rm -rf $(OBJS) $(LOBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re