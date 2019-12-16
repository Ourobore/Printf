# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 12:57:14 by lchapren          #+#    #+#              #
#    Updated: 2019/12/11 11:10:51 by lchapren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(FLIBFT)	:	./libft-srcs/ft_substr.c ./libft-srcs/ft_calloc.c ./libft-srcs/ft_bzero.c

$(LSRCS)	:	$(FLIBFT)

$(SRCS)		: