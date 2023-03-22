#EXEC#

NAME	= philo

#FLAGS & COMMANDS#

GCC		= gcc -Wall -Wextra -Werror
FSAN	= -fsanitize=thread -g
RM		= rm -rf

#PATH#

INC		= -Iincludes
SRC_DIR	= sources/
BRN_DIR	= $(SRC_DIR)brains/
INP_DIR	= $(SRC_DIR)input/
UTL_DIR	= $(SRC_DIR)utils/

DRV_DIR	= $(SRC_DIR)driver/
MAIN	= $(DRV_DIR)main.c

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

norm	:
	norminette $(SRC_DIR)
	norminette includes/

fsan	: fclean $(OBJS)
	$(GCC) $(INC) -o $(NAME) $(MAIN) $(OBJS) $(FSAN)

re		: fclean all

.PHONY	:  all clean fclean norm fsan re