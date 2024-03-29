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
PRINTFDIR	= ./ft_printf
PRINTFFILE	= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3
MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit -lz
RM			= rm -f

SRCS = \
	atof.c \
	color.c \
	complex.c \
	fractol.c \
	image.c \
	init.c \
	keyboard.c \
	main.c \
	mouse.c \
	print.c \

OBJS = $(SRCS:c=o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLXDIR)
	make -C $(PRINTFDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXFLAGS) $(MLXDIR)/$(MLXFILE) $(PRINTFDIR)/$(PRINTFFILE)

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C $(PRINTFDIR) clean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(MLXFILE) $(PRINTFFILE)

fclean: clean
	make -C $(PRINTFDIR) fclean
	make -C $(MLXDIR) clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
