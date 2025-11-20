CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-Iincludes
SRC_DIR		:=	src/
BUILD_DIR	:=	.build/
LIBFT		:=	libft/libft.a
MAKEFLAGS	+=	-j $$(nproc)

BASENAME	:=	ft_printf \
				ft_print_char \
				ft_print_str \
				ft_print_pointer \
				ft_print_nbr \
				ft_print_unsigned \
				ft_print_null \
				ft_print_hex

BONUS_BASE	:=	ft_printf_bonus \
				ft_print_char_bonus \
				ft_print_str_bonus \
				ft_print_pointer_bonus \
				ft_print_nbr_bonus \
				ft_print_unsigned_bonus \
				ft_print_null_bonus \
				ft_print_hex_bonus \
				parser_bonus \
				utils_bonus \

HEADERS		:=	includes/libft.h includes/ft_printf.h
HEADERS_B	:=	includes/ft_printf_bonus.h includes/parser_bonus.h includes/libft.h
SRCS		:=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(BASENAME)))
OBJS		:=	$(addsuffix .o, $(addprefix $(BUILD_DIR),$(BASENAME)))
B_SRCS		:=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(BONUS_BASE)))
B_OBJS		:=	$(addsuffix .o, $(addprefix $(BUILD_DIR),$(BONUS_BASE)))
NAME		:=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(HEADERS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)

clean:
	rm -rf $(BUILD_DIR)
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
