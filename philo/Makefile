# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 10:11:18 by fdessoy-          #+#    #+#              #
#    Updated: 2024/07/02 12:31:34 by fdessoy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC			= 	cc
FLAGS		= 	-Wall -Werror -Wextra -g -pedantic 
LIBS 		= 	philo.h
SRC 		=	philo.c\
				printer.c\
				parsing.c\
				utils.c\
				struct_utils.c\
				main.c\
				flags.c\
				routine.c

OBJ  		= 	$(SRC:.c=.o) 

$(NAME)		:	$(OBJ)
				cc $(FLAGS) $(OBJ) -o $(NAME)

%.o			:	%.c
				$(CC) $(FLAGS) -c $< -o $@

all			:	$(NAME) 

clean		:	
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY 		: 	all clean fclean re 
