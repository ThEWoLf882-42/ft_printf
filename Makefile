SRCS =	ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_strlen.c\
		ft_puthex.c\
		ft_ahex.c\
		ft_putnbr.c\
		ft_putun.c\


NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}


FLAGS = -Wall -Wextra -Werror 
CC = cc
RM = rm -f

%.o: %.c ft_printf.h
			${CC} ${FLAGS} -I. -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME} :   ${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} $(OBJSB)

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re