# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgaric <pgaric@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 10:22:26 by pgaric            #+#    #+#              #
#    Updated: 2022/05/26 11:17:07 by pgaric           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_itoa	\
			ft_printf	\
			ft_printhexad	\
			ft_printnumber	\
			ft_printpointer	\
			ft_printunsigned	\
			ft_printputchar	\
			ft_printstring	\
			ft_printstring	\
			ft_putchar_fd	\

SRCS	= $(addsuffix .c, ${SRC})

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc
RM	= rm -f
AR	= ar rc
RN	= ranlib

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all