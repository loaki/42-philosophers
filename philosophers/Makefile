.PHONY: all clean fclean re norme

##CC = clang-9
##CC = clang -g ## clang-9 doesn't work on my ubuntu
CC = gcc

FLAGS = -Wall -Wextra -Werror

PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker

SRC_PATH = ./srcs
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

INC_NAME = push_swap.h
SRC_NAME = push_swap.c checker.c init_struct.c parse_arg.c instr.c op_p.c op_r.c\
	op_rr.c op_s.c check_stack.c sort_stack.c insertion_sort.c display.c print.c\
	get.c check_print.c
LIB_NAME = ft_atoi.c ft_isascii.c ft_lstadd_front_bonus.c ft_lstmap_bonus.c\
	ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strmapi.c ft_substr.c ft_bzero.c\
	ft_isdigit.c ft_lstclear_bonus.c ft_lstnew_bonus.c ft_memcpy.c ft_putnbr_fd.c\
	ft_strjoin.c ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c ft_lstdelone_bonus.c\
	ft_lstsize_bonus.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strnstr.c ft_toupper.c\
	ft_isalnum.c ft_itoa.c ft_lstiter_bonus.c ft_memccpy.c ft_memset.c ft_split.c ft_strlcpy.c\
	ft_strrchr.c ft_isalpha.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_memchr.c ft_putchar_fd.c\
	ft_strchr.c ft_strlen.c ft_strtrim.c
PUSH_SWAP_OBJ_NAME = push_swap.o init_struct.o parse_arg.o instr.o op_p.o op_r.o op_rr.o op_s.o\
	check_stack.o sort_stack.o insertion_sort.o display.o print.o get.o check_print.o
CHECKER_OBJ_NAME = checker.o init_struct.o parse_arg.o instr.o op_p.o op_r.o op_rr.o op_s.o\
	check_stack.o display.o print.o check_print.o
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
PUSH_SWAP_OBJ = $(addprefix $(OBJ_PATH)/,$(PUSH_SWAP_OBJ_NAME))
CHECKER_OBJ = $(addprefix $(OBJ_PATH)/,$(CHECKER_OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(OBJ) $(OBJLIB)
	${CC} -Wall -Wextra -Werror -I ${INC_PATH} -o ${PUSH_SWAP_NAME} ${OBJLIB} ${PUSH_SWAP_OBJ}

$(CHECKER_NAME): $(OBJ) $(OBJLIB)
	${CC} -Wall -Wextra -Werror -I ${INC_PATH} -o ${CHECKER_NAME} ${OBJLIB} ${CHECKER_OBJ}

#valgrind --leak-check=full

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	${CC} -I ${INC_PATH} -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	rm -rf ./obj $(PUSH_SWAP_NAME)
	rm -rf ./obj $(CHECKER_NAME)

re: fclean all