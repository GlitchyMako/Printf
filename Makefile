# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalmeida <jalmeida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 19:03:54 by jalmeida          #+#    #+#              #
#    Updated: 2021/03/30 19:03:54 by jalmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

NAME		= libftprintf.a
INCLUDE		= ft_printf.h

SRCS		= ft_printf.c ft_printf_c.c ft_printf_d.c ft_printf_flags.c \
			ft_printf_p.c ft_printf_pct.c ft_printf_u.c ft_printf_s.c \
			ft_printf_utils.c ft_printf_x.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			ar -rcs $(NAME) $(OBJS)
			ranlib	$(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 
