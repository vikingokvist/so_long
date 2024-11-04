# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 18:12:14 by ctommasi          #+#    #+#              #
#    Updated: 2024/11/01 18:12:16 by ctommasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I ./MLX42/include
RM = rm -f
NO_PRINT = --no-print-directory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIB_DIR = MLX42/build
MINILIB = $(MINILIB_DIR)/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_SRC = src/main.c src/init_window.c src/init_map.c src/hook_and_loop.c \
	src/keypress.c src/destroy.c src/free_data.c src/render_background.c 

OBJS_SRC = $(SRCS_SRC:.c=.o)

ORANGE = \033[38;5;214m
GREEN = \033[38;5;82m
RESET = \033[0m

#----------------------------------------------------------------------
#			   SO_LONG
#----------------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
	@echo "$(ORANGE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_SRC) $(MINILIB) $(LIBFT) -o $(NAME) 
	@echo "$(GREEN)Executable built: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_SRC)
	@echo "$(GREEN)All object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Executable removed.$(RESET)"

#----------------------------------------------------------------------
#				LIBFT
#----------------------------------------------------------------------
libft: $(LIBFT)

$(LIBFT):
	@echo "$(ORANGE)Building libft...$(RESET)"
	@make $(NO_PRINT) -C $(LIBFT_DIR)

clean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Libft cleaned.$(RESET)"

fclean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Libft executable removed.$(RESET)"

#----------------------------------------------------------------------
#			     MINILIB
#----------------------------------------------------------------------
minilib: $(MINILIB)

$(MINILIB):
	@echo "$(ORANGE)Building minilibx...$(RESET)"
	@cmake -B $(MINILIB_DIR) -S MLX42 && make -C $(MINILIB_DIR)

clean_minilib:
	@make -C $(MINILIB_DIR) clean || true
	@echo "$(GREEN)Minilibx cleaned.$(RESET)"

fclean_minilib:
	@make -C $(MINILIB_DIR) clean || true
	@echo "$(GREEN)Minilibx executable removed.$(RESET)"

#----------------------------------------------------------------------
#----------------------------------------------------------------------

re: fclean all

.PHONY: all clean fclean libft clean_libft fclean_libft \
	minilib clean_minilib fclean_minilib
