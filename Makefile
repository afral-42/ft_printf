CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	-Iincludes
#DEPSFLAGS	:=	-MD -MP -MM
SRC_DIR		:=	src/
BUILD_DIR	:=	.build/
MAKEFLAGS	+=	-j $$(nproc)

BASENAME	:=	ft_printf \
				ft_print_char \
				ft_print_str \
				ft_print_pointer \
				ft_print_nbr \
				ft_print_unsigned \
				ft_print_null \
				ft_print_hex

SRCS		:=	$(addsuffix .c, $(addprefix $(SRC_DIR),$(BASENAME)))
OBJS		:=	$(addsuffix .o, $(addprefix $(BUILD_DIR),$(BASENAME)))
DEPS		:=	$(addsuffix .d, $(addprefix $(BUILD_DIR),$(BASENAME)))
NAME		:=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS) #$(DEPSFLAGS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#-include $(DEPS)
