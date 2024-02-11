NAME	= readcsv

INC		= ./inc
GNL		= ./get_next_line
GNL_A	= $(addprefix $(GNL), libgnl.a)
SRC_DIR	= ./srcs
OBJ_DIR	= ./objs
SRCS	= \
		main.c \
		get_fd.c \
		utils.c \
		chk_data.c \
		get_value/get_data.c \
		table_operations.c \
		utils/ft_strtrim.c \
		utils/str_utils.c \
		utils/csv_split.c \
		get_datatype/get_datatype.c \
		get_datatype/identify.c

SRC_PATH = $(addprefix $(SRC_DIR)/, $(SRCS))


OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRCS))

CC		= gcc
FLAGS	=  -I$(INC)
RM		= rm -rf

all:		$(OBJ_DIR) $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				@mkdir -p $(@D)
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