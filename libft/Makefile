#Directories

VPATH = src/ft_printf:src/get_next_line:src/libft

OBJ_DIR = obj

INC_DIR = inc

#Files
LIBFT_O = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
		ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o \
		ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o \
		ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
		ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o \
		ft_strtrim.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o \
		ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
		ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o \
		ft_lstnew.o ft_lstsize.o ft_lstadd_back.o ft_lstadd_front.o ft_itoa_base.o \
		ft_strsnjoin.o ft_lastloc.o ft_intnchr.o ft_split_charset.o ft_strcmp.o \
		ft_doublepointer_free.o

FT_PRINTF_O = ft_printf.o ft_printf_specified.o ft_printf_order.o \
			ft_printf_write_extra.o

GET_NEXT_LINE_O = get_next_line.o get_next_line_utils.o

OBJ_F = $(LIBFT_O) $(FT_PRINTF_O) $(GET_NEXT_LINE_O)

OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_F))

DEPS = $(OBJS:.o=.d)

#Compiler Flags
FLAGS = -Wall -Wextra -Werror

#Compiler
CC = cc

#Linker
LNK = ar
LNK_FLAGS = -rc

#Target name
NAME = libft.a

#Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	@$(LNK) $(LNK_FLAGS) $(NAME) $(OBJS)
	@echo $(YELLOW)libft - Linking:$(NO_COLOR) $(NAME)

$(OBJ_DIR)/%.o:%.c Makefile
	@$(CC) -MMD -I$(INC_DIR) $(FLAGS) -c $< -o $@
	@echo $(YELLOW)libft - Compiling object file:$(NO_COLOR) $(notdir $@)

clean:
	@rm -rf $(OBJ_DIR)
	@echo $(YELLOW)libft - Removing:$(NO_COLOR) Object and dependency files

fclean: clean
	@rm -f $(NAME)
	@echo $(YELLOW)libft - Removing:$(NO_COLOR) $(NAME)

re: fclean all

-include $(DEPS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: clean fclean all re
