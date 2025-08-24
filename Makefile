MAKEFLAGS += --no-print-directory

NAME = miniRT

SRC_DIR         = source
OBJ_DIR         = build
LIB_DIR         = libs
INC_DIR         = includes

UTILS_DIR       = $(SRC_DIR)/utils
VALIDATION_DIR  = $(SRC_DIR)/validation
PARSE_DIR       = $(SRC_DIR)/parse
GRAPHICS_DIR    = $(SRC_DIR)/graphics
RAY_TRACING_DIR = $(SRC_DIR)/ray_tracing
VECTOR_DIR      = $(SRC_DIR)/vector

MINILIBX_DIR    = $(LIB_DIR)/minilibx_macos
LIBFT_DIR       = $(LIB_DIR)/libft

SRCS = \
	$(SRC_DIR)/main.c \
	$(UTILS_DIR)/map_utils.c \
	$(UTILS_DIR)/print_utils.c \
	$(VALIDATION_DIR)/global_functions.c \
	$(VALIDATION_DIR)/validation.c \
	$(VALIDATION_DIR)/file_handler.c \
	$(VALIDATION_DIR)/ambient.c \
	$(VALIDATION_DIR)/camera.c \


OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION -fsanitize=address

INCS  = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
LIBS  = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx
FMS   = -framework OpenGL -framework AppKit

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	MINILIBX_DIR = $(LIB_DIR)/minilibx-linux
	INCS  = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
	LIBS  = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lm -lX11 -lXext
	FMS   =
endif

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): mlx lib $(OBJS)
	@echo "Linking $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBS) $(FMS) -o $(NAME)

lib:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MINILIBX_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re lib mlx
