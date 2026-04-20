CC = cc
CFLAGS = -Wextra -Werror -Wall

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = lib
FT_PRINTF_SRC_DIR = $(SRC_DIR)/ft_printf
FT_PRINTF_OBJ_DIR = $(OBJ_DIR)/ft_printf
LIBFT_SRC_DIR = $(SRC_DIR)/libft
LIBFT_OBJ_DIR = $(OBJ_DIR)/libft

LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_free_array.c \
	ft_arraysize.c ft_arrayadd_back.c


FT_PRINTF_SRC = ft_printf.c ft_sort.c ft_putchar_p.c ft_putstr_p.c ft_puthex.c\
	ft_putupphex.c ft_putptr.c ft_putun.c ft_putnbr_p.c ft_printr.c

FT_PRINTF_OBJS = $(addprefix $(FT_PRINTF_OBJ_DIR)/, $(FT_PRINTF_SRC:%.c=%.o))
LIBFT_OBJS = $(addprefix $(LIBFT_OBJ_DIR)/, $(LIBFT_SRC:%.c=%.o))

FT_PRINTF_NAME = $(LIB_DIR)/ft_printf.a
LIBFT_NAME = $(LIB_DIR)/libft.a
ALL_NAME = $(LIB_DIR)/libft_ft_printf.a

all: $(ALL_NAME)

$(ALL_NAME): $(FT_PRINTF_OBJS) $(LIBFT_OBJS) | $(LIB_DIR)
	ar rcs $(ALL_NAME) $(LIBFT_OBJS) $(FT_PRINTF_OBJS)
	ranlib $(ALL_NAME)

ft_printf: $(FT_PRINTF_NAME)

$(FT_PRINTF_NAME): $(FT_PRINTF_OBJS) | $(LIB_DIR)
	ar rcs $(FT_PRINTF_NAME) $(FT_PRINTF_OBJS)
	ranlib $(FT_PRINTF_NAME)

$(FT_PRINTF_OBJ_DIR)/%.o: $(FT_PRINTF_SRC_DIR)/%.c | $(FT_PRINTF_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(FT_PRINTF_OBJ_DIR):
	mkdir -p $(FT_PRINTF_OBJ_DIR)

libft: $(LIBFT_NAME)

$(LIBFT_NAME): $(LIBFT_OBJS) | $(LIB_DIR)
	ar rcs $(LIBFT_NAME) $(LIBFT_OBJS)
	ranlib $(LIBFT_NAME)

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_SRC_DIR)/%.c | $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(LIBFT_OBJ_DIR):
	mkdir -p $(LIBFT_OBJ_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

clean:
	rm -f $(LIBFT_OBJS) $(FT_PRINTF_OBJS)

fclean: clean
	rm -rf $(LIB_DIR) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re ft_printf libft
