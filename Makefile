#Colors
YELLOW = "\e[33m"
GREEN = "\e[32m"
NO_COLOR = "\e[0m"

# Folders
VPATH = src:src/parser:src/math:src/mlxgraphics
OBJ_FOLDER = obj
LFT_FOLDER = libft
MLX_FOLDER = MLX42
INC = -I./inc -I./libft/inc -I./$(MLX_FOLDER)/include

# Files
OBJ = cubed.o parser.o error.o parser_util.o parse_color.o parse_element.o \
		parse_map.o parse_texture.o draw.o movement.o\
		valid_map.o vector.o raycasting.o key_hook.o\

LFT = $(LFT_FOLDER)/libft.a
MLX = $(MLX_FOLDER)/libmlx42.a
DEPS = $(OBJ_DIR:.o=.d)
OBJ_DIR = $(addprefix $(OBJ_FOLDER)/, $(OBJ))

# Project
NAME = cub3D
PROJECT = cub3D

# Compilation/Linking
CC = cc
LFLAGS = -Wall -Wextra -Werror -g
CFLAGS = -Wall -Wextra -Werror -MMD $(INC) -g
MLXFLAGS = -ldl -lglfw -pthread -lm

# Rules
all: $(OBJ_FOLDER) mlibft mmlx $(NAME)

# Linking
$(NAME): $(LFT) $(MLX) $(OBJ_DIR)
	@$(CC) $(LFLAGS) -o $(NAME) $(OBJ_DIR) $(LFT) $(MLX) $(MLXFLAGS)
	@echo $(YELLOW)$(PROJECT) - Linking:$(NO_COLOR) $(NAME)

# Compilation
$(OBJ_FOLDER)/%.o: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo $(YELLOW)$(PROJECT) - Compiling object file:$(NO_COLOR) $(notdir $@)

$(LFT): mlibft

$(MLX): mmlx

mlibft:
	@$(MAKE) --no-print-directory -C $(LFT_FOLDER)

mmlx:
	@cd $(MLX_FOLDER); cmake -B .; make --no-print-directory

# Other rules
clean:
	@rm -rf $(OBJ_FOLDER)
	@rm -rf $(LFT)
	@$(MAKE) --no-print-directory -C $(LFT_FOLDER) fclean
	@$(MAKE) --no-print-directory -C $(MLX_FOLDER) clean
	@echo $(YELLOW)$(PROJECT) - Removing:$(NO_COLOR) Object, library and dependency files

fclean: clean
	@rm -rf $(NAME)
	@echo $(YELLOW)$(PROJECT) - Removing:$(NO_COLOR) $(NAME)

re: fclean all

.PHONY: clean fclean re all mlibft mmlx $(OBJ_FOLDER)

# Utils
$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

-include $(DEPS)
