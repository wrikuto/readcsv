NAME	= readcsv

INC		= ./inc
GNL		= ./get_next_line
GNL_A	= $(addprefix $(GNL), libgnl.a)
SRC_DIR	= ./srcs
OBJ_DIR	= ./objs
SRCS	=\
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/get_fd.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/get_data.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:		$(OBJ_DIR) $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(GNL_A)
				$(CC) $(FLAGS) $(OBJS) -L$(GNL) -lgnl -o $(NAME)

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