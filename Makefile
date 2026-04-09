CC = cc
CFLAGS = -Wextra -Werror -Wall

SRC_DIR = src
OBJ_DIR = obj
#BIN_DIR = bin
INC_DIR = include

ATROMBEL_DIR = atrombel
ATROMBEL_SRC_DIR = $(SRC_DIR)/$(ATROMBEL_DIR)
ATROMBEL_OBJ_DIR = $(OBJ_DIR)/$(ATROMBEL_DIR)

CGASSER_DIR = cgasser
CGASSER_SRC_DIR = $(SRC_DIR)/$(CGASSER_DIR)
CGASSER_OBJ_DIR = $(OBJ_DIR)/$(CGASSER_DIR)


CFILES = main.c 

SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))


ATROMBEL_CFILES =

ATROMBEL_SRCS = $(addprefix $(ATROMBEL_SRC_DIR)/, $(ATROMBEL_CFILES))
ATROMBEL_OBJS = $(addprefix $(ATROMBEL_OBJ_DIR)/, $(ATROMBEL_CFILES:.c=.o))
ATROMBEL_NAME = atrombel


CGASSER_CFILES = ft_parse.c

CGASSER_SRCS = $(addprefix $(CGASSER_SRC_DIR)/, $(CGASSER_CFILES))
OBJS = $(addprefix $(GASSER_OBJ_DIR), $(CGASSER_CFILES:.c=.o))
CGASSER_NAME = cgasser


LIBFT_DIR = libft
LIBFT_LIB_DIR = $(LIBFT_DIR)/lib
LIBFT_A = $(LIBFT_LIB_DIR)/libft_ft_printf.a
LIBFT_INC_DIR = $(LIBFT_DIR)/include


HFILES = minishell.h atrombel.h cgasser.h

NAME = minishell

all: $(NAME)
#$(BIN_DIR)/$(NAME)

$(NAME): $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(ATROMBEL_OBJS) $(CGASSER_OBJS) $(LIBFT_A) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_A): 
	$(MAKE) -C $(LIBFT_DIR)

#$(BIN_DIR):
#	mkdir -p $(BIN_DIR)



atrombel: $(ATROMBEL_NAME) 

$(ATROMBEL_NAME): $(ATROMBEL_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(ATROMBEL_OBJS) $(LIBFT_A) -o $@

$(ATROMBEL_OBJ_DIR)/%.o: $(ATROMBEL_SRC_DIR)/%.c | $(ATROMBEL_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(ATROMBEL_OBJ_DIR): $(OBJ_DIR)
	mkdir -p $(ATROMBEL_OBJ_DIR)



cgasser: $(CGASSER_NAME) 

$(CGASSER_NAME): $(CGASSER_OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(CGASSER_OBJS) $(LIBFT_A) -o $@

$(CGASSER_OBJ_DIR)/%.o: $(CGASSER_SRC_DIR)/%.c | $(CGASSER_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(CGASSER_OBJ_DIR): $(OBJ_DIR)
	mkdir -p $(CGASSER_OBJ_DIR)



debug: $(OBJS) $(LIBFT_A)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT_A) -I $(INC_DIR) -I $(LIBFT_INC_DIR)

valgrind: $(OBJS) $(LIBFT_A)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT_A) -I $(INC_DIR) -I $(LIBFT_INC_DIR)
	valgrind --leak-check=yes --track-origins=yes ./push_swap 7 89 293

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

cleanatrombel:
	rm -rf $(ATROMBEL_OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fcleanatrombel: clean atrombel
	rm -rf $(ATROMBEL_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

cleancgasser:
	rm -rf $(CGASSER_OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fcleancgasser: clean cgasser
	rm -rf $(CGASSER_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all atrombel cgasser debug valgrind clean fclean cleanatrombel fcleanatrombel cleancgasser fcleancgasser re
