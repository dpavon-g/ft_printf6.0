# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 18:01:15 by dpavon-g          #+#    #+#              #
#    Updated: 2021/04/14 15:41:50 by dpavon-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror 

CC = cc

SRCS = 		ft_bzero.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strlcpy.c\
			ft_strlcat.c\
			ft_strnstr.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_split.c\
			ft_strmapi.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\

BONUS =		ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c
			

OBJS = $(SRCS:.c=.o)
BONUSO = $(BONUS:.c=.o)

$(NAME):
		@$(CC) $(CFLAGS) -c $(SRCS)
		@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
			@rm -rf $(OBJS)
			@rm -rf $(BONUSO)

fclean:		clean
			@rm -rf $(NAME)
			@rm -rf $(BONUSO)

bonus: 	$(NAME) $(BONUSO)
		@ar rcs $(NAME) $(BONUSO)

re: fclean all

.PHONY: 			all clean fclean re
