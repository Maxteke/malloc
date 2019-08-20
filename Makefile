##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= ./my_malloc.c \
		  ./func_malloc.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra -W -pedantic -fpic
LDFLAGS = -shared 

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
