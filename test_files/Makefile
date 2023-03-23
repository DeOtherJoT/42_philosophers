#EXEC#

NAME	= test.out

#FLAGS & COMMANDS#

GCC		= gcc -Wall -Wextra -Werror
FSAN_T	= -fsanitize=thread -g
FSAN_A	= -fsanitize=address -g

#PATH#

INC		= -I../includes
SRC_DIR	= ../sources/
BRN_DIR	= $(SRC_DIR)brains/
INP_DIR	= $(SRC_DIR)input/
UTL_DIR	= $(SRC_DIR)utils/

#TEST FILE#

MAIN	= $(TARGET).c

#SOURCE FILES#

SRCS	=	$(addprefix $(BRN_DIR), begin.c ft_eat.c ft_sleep.c ft_think.c init_philos.c) \
			$(addprefix $(INP_DIR), parse_args.c) \
			$(addprefix $(UTL_DIR), utils1.c utils2.c)

OBJS	=	$(SRCS:.c=.o)

#RECIPES#

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS)

%.o		: %.c
	$(GCC) $(INC) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

fsan-t	: fclean $(OBJS)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(FSAN_T)


fsan-a	: fclean $(OBJS)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(FSAN_A)

.PHONY	:  all clean fclean norm fsan-a fsan-t