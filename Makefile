NAME = philo

SRCS =	philo_main.c\
		utils.c\
		free.c\

INCLUDE	= includes

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -g -pthread

.c.o:
	${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : 	clean
		${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
