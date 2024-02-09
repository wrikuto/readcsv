NAME	= readcsv

INC		= ./inc
GNL		= ./get_next_line
GNL_A	= $(addprefix $(GNL), libgnl.a)
SRC_DIR	= ./srcs
OBJ_DIR	= ./objs
SRCS	=\
		./srcs/main.c \
		./srcs/get_fd.c \
		./srcs/utils.c \
		./srcs/chk_data.c \
		./srcs/get_data.c \
		./srcs/table_operations.c \
		./srcs/utils/ft_strtrim.c \
		./srcs/utils/str_utils.c

# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS = $(SRCS:.c=.o)

CC		= gcc
FLAGS	=  -I$(INC)
RM		= rm -f

all:		$(OBJ_DIR) $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(GNL_A)
				$(CC) $(FLAGS) $(OBJS) -L$(GNL) -lgnl -lreadline -o $(NAME)

# $(NAME): $(OBJS) $(GNL_A)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)


$(GNL_A):
				$(MAKE) -s -C $(GNL)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				$(MAKE) clean -s -C $(GNL)
				$(RM) $(OBJ_DIR)/*

fclean:			clean
				$(MAKE) fclean -s -C $(GNL)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re