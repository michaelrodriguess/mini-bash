SRC		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_lstsize.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstdisplay.c ft_lstclear.c ft_strcmp.c ft_abs.c get_next_line.c get_next_line_utils.c ft_array_len.c ft_strtrim_free.c ft_ahtoi.c ft_strchri.c strjoinchr.c remove_substr.c insert_substr.c ft_isnum.c ft_size_matriz.c

OBJS	= ${SRC:.c=.o}

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		$(NAME)

clean:
			rm -f ${OBJS} ${OBJS_B}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
