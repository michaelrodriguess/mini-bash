SRCS			=	./sources/main.c \
					./sources/handling/handle_signals.c \
					./sources/handling/handle_redirect/redirect.c \
					./sources/handling/handle_redirect/redirect2.c \
					./sources/handling/handle_parser/utils_pipe.c \
					./sources/handling/handle_parser/parser_args.c \
					./sources/handling/handle_parser/parser_args2.c \
					./sources/handling/handle_memory/clear_memory.c \
					./sources/handling/handle_error/msg_error.c \
					./sources/handling/handle_error/check_input.c \
					./sources/handling/handle_error/valid_pipe_redirect.c \
					./sources/handling/handle_parser/expand_envvar.c \
					./sources/handling/handle_parser/cmd_finder.c \
					./sources/handling/handle_parser/cmd_finder2.c \
					./sources/handling/handle_pipes/pipes.c \
					./sources/tokenization/lst_token2.c\
					./sources/tokenization/lst_token.c\
					./sources/tokenization/lexer.c \
					./sources/tokenization/sentence_lst.c \
					./sources/built-ins/util_builtins.c \
					./sources/built-ins/pwd.c \
					./sources/built-ins/echo.c \
					./sources/built-ins/cd.c \
					./sources/built-ins/exit.c \
					./sources/built-ins/env.c \
					./sources/built-ins/unset.c \
					./sources/built-ins/export.c \
					./sources/exec/executor.c \
					./sources/exec/exec_utils.c \
					./sources/exec/execute_pipeline.c \

NAME			= minishell
OBJS			= $(SRCS:.c=.o)
LIBS			= sources/libft/libft.a
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include ##MAC
##CFLAGS			= -Wall -Wextra -Werror ##LINUX


$(NAME):	$(SRCS) $(LIBS)
		$(CC) $(CFLAGS) $(SRCS) $(LIBS) -g -lreadline -o $(NAME)

$(LIBS): sources/libft
	make -C sources/libft/ all

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make -C sources/libft/ clean

fclean:	clean
	   	$(RM) $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re
