NAME    = push_swap

SRCS    =   ./main.c ./ft_atoi.c ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew_int.c ./ft_lstnew.c ./ft_lstsize.c ./make_binary.c ./make_decimal.c ./cut_functions.c ./commands.c ./check_function.c ./ft_sort_three.c

GCC        = gcc

CFLAGS    = -Wall -Wextra -Werror

OBJS    = ${SRCS:.c=.o}

RM        = rm -rf

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${GCC} ${OBJS} -o ${NAME}

all:    ${NAME}

clean:
	${RM} ${OBJS}

fclean:    clean
		${RM} ${NAME}

re:        fclean all

.PHONY: bonus re clean fclean all
