##
## Makefile for lem-in in /home/joliva_d/rendu/lem-in
## 
## Made by jolivald
## Login   <joliva_d@epitech.net>
## 
## Started on  Thu May  1 12:38:43 2014 jolivald
##

COLORCC	=	/usr/bin/colorgcc.pl

CC	=	gcc

SRC	=	sort_ways.c		\
		end_aff_functs.c	\
		quick_sort.c		\
		add_elem_in_list.c	\
		get_data_utils.c	\
		graph_utils.c		\
		end_display.c		\
		get_data.c		\
		new_rooms.c		\
		basics.c		\
		basics_2.c		\
		graph.c			\
		my_realloc.c		\
		my_str_to_wordtab.c	\
		get_next_line.c		\
		display.c		\
		functs.c		\
		onsenfoudsa.c		\
		onsenfoupasdca.c	\
		Algo/process_ants.c	\
		Algo/functions_ants.c	\
		Algo/functions_ants_2.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

CFLAGS	=	-I./inc/ -Wall -Wextra


all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)
fclean	:	clean
		rm -f $(NAME)
re	:	fclean all
