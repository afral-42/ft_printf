CC        := cc
CFLAGS    := -Wall -Wextra -Werror
CPPFLAGS  := -Iincludes
CPPFLAGS_B:= -Iincludes/bonus
SRC_DIR   := src/
BUILD_DIR := .build/
BUILD_BONUS_DIR := $(BUILD_DIR)bonus/
LIBFT     := libft/libft.a

BASENAME  := ft_printf \
             ft_print_char \
             ft_print_str \
             ft_print_pointer \
             ft_print_nbr \
             ft_print_unsigned \
             ft_print_null \
             ft_print_hex

BONUS_BASE := ft_printf_bonus \
              ft_print_char_bonus \
              ft_print_str_bonus \
              ft_print_pointer_bonus \
              ft_print_nbr_bonus \
              ft_print_unsigned_bonus \
              ft_print_null_bonus \
              ft_print_hex_bonus \
              parser_bonus \
              utils_bonus

HEADERS   := includes/libft.h includes/ft_printf.h
HEADERS_B := includes/bonus/ft_printf.h includes/bonus/parser_bonus.h includes/bonus/libft.h

SRCS      := $(addprefix $(SRC_DIR), $(addsuffix .c, $(BASENAME)))
OBJS      := $(addprefix $(BUILD_DIR), $(addsuffix .o, $(BASENAME)))
B_SRCS    := $(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_BASE)))
B_OBJS    := $(addprefix $(BUILD_BONUS_DIR), $(addsuffix .o, $(BONUS_BASE)))

NAME      := libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_BONUS_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_BONUS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS_B) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_BONUS_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_BONUS_DIR)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

bonus: $(B_OBJS) $(LIBFT) $(HEADERS_B)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(B_OBJS)

$(LIBFT):
	make -C libft/

.PHONY: all clean fclean re bonus
