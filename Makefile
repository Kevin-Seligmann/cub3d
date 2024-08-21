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
OBJ = extension_checker.o get_map_info.o is_map_line.o parser_main.o process_color.o\
	process_config.o process_map.o process_texture.o cubed.o draw.o draw_mini.o\
	key_hook.o movement.o raycasting.o vector.o draw_mini_door.o\
	door.o windows_size.o key_hook_2.o parse_sprite.o \
	sprite.o draw_sprite.o exit.o draw_sprite_2.o square_enclosed.o


LFT = $(LFT_FOLDER)/libft.a
MLX = $(MLX_FOLDER)/libmlx42.a
DEPS = $(OBJ_DIR:.o=.d)
OBJ_DIR = $(addprefix $(OBJ_FOLDER)/, $(OBJ))

# Project
NAME = cub3D
PROJECT = cub3D

# Compilation/Linking
CC = cc
LFLAGS =  -Wall -Wextra -Werror -g
CFLAGS =  -Wall -Wextra -Werror -MMD $(INC) -g
MLXFLAGS = -ldl -lglfw -pthread -lm

# Rules
all: $(MLX_FOLDER) $(OBJ_FOLDER) mlibft mmlx $(NAME)

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

$(MLX_FOLDER):
	git clone https://github.com/codam-coding-college/MLX42.git
	
debug: all
	valgrind --suppressions=cub3d.supp --track-fds=yes --leak-check=full --show-leak-kinds=all ./cub3D maps/tests/sprites.cub

gensupp: all
	valgrind --suppressions=cub3d.supp -s --track-fds=yes --leak-check=full --show-leak-kinds=all --gen-suppressions=yes ./cub3D maps/tests/sprites.cub

-include $(DEPS)
