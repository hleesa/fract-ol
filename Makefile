# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:35:32 by salee2            #+#    #+#              #
#    Updated: 2022/09/22 13:35:33 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= fractol
MLXDIR		= ./minilibx_opengl_20191021
MLXFILE		= libmlx.a


CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3 -I$(PRINTFDIR)
AR			= ar rcs
RM			= rm -f

SRCS_COMMON = \

SRCS_MANDA = \
	complex.c \
	image.c \
	init.c \
	main.c \
	mandelbrot_set.c \

SRCS_BONUS = \

OBJS_MANDA = $(SRCS_MANDA:c=o)

all: $(NAME)

$(NAME): $(OBJS_MANDA)
	make -C $(MLXDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXDIR)/$(MLXFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(MLXDIR) clean
	$(RM) $(OBJS_MANDA) $(OBJS_BONUS) $(MLXFILE)

fclean: clean
	make -C $(MLXDIR) clean
	$(RM) $(NAME) $(BONUS)

re: fclean
	make all

.PHONY: all bonus clean fclean re
