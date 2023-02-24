# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalta <spalta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:42:30 by spalta            #+#    #+#              #
#    Updated: 2023/02/01 17:53:40 by spalta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CL = client.c
SRCS_SR = server.c
SRCS = ft_printf.c
OBJS_SRCS = $(SRCS:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o) $(OBJS_SRCS)
OBJS_SR = $(SRCS_SR:.c=.o) $(OBJS_SRCS)

NAME_CL = client
NAME_SR = server
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME_SR) $(NAME_CL)

$(NAME_SR): $(OBJS_SR)
	gcc $(CFLAGS) $(OBJS_SR) -o $(NAME_SR)

$(NAME_CL): $(OBJS_CL)
	gcc $(CFLAGS) $(OBJS_CL) -o $(NAME_CL)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_CL) $(OBJS_SR) $(OBJS_SRCS)

fclean: clean
	rm -rf $(NAME_SR) $(NAME_CL)

re: fclean all

.PHONY: all clean fclean re