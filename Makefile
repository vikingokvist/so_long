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
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -I ./MLX42/include
RM = rm -f
NO_PRINT = --no-print-directory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIB_DIR = MLX42/build
MINILIB = $(MINILIB_DIR)/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_SRC = src/main.c src/init_struct.c src/check_ber_file.c src/check_map_rectangle.c \
	src/read_map.c src/init_window.c src/hook_and_loop.c src/keypress.c src/destroy.c \
	src/free_data.c src/render_background.c src/render_player.c src/check_walls.c \
	src/get_player_pos.c src/check_map_dupes.c src/check_map_doable.c \

OBJS_SRC = $(SRCS_SRC:.c=.o)

SRCS_BONUS = bonus/main_bonus.c bonus/keypress_bonus.c bonus/hook_and_loop_bonus.c\
	bonus/death_bonus.c bonus/render_background_bonus.c bonus/render_moves_bonus.c \
	bonus/check_map_doable_bonus.c bonus/init_struct_bonus.c bonus/check_ber_file_bonus.c \
	bonus/check_map_rectangle_bonus.c bonus/read_map_bonus.c bonus/init_window_bonus.c \
	bonus/free_data_bonus.c bonus/check_walls_bonus.c \
	bonus/check_map_dupes_bonus.c bonus/get_positions_bonus.c \
	bonus/render_player_movement_bonus.c bonus/textures_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@echo "$(ORANGE)Linking Bonus...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MINILIB) $(LIBFT) -o $(NAME_BONUS) 
	@echo "$(GREEN)Executable built: $(NAME_BONUS)$(RESET)"

clean:
	@$(RM) $(OBJS_SRC)
	@$(RM) $(OBJS_BONUS)
	@echo "$(GREEN)All object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "$(GREEN)Executable removed.$(RESET)"

#----------------------------------------------------------------------
#				LIBFT
#----------------------------------------------------------------------
libft: $(LIBFT)

$(LIBFT):
	@echo "$(ORANGE)Building libft...$(RESET)"
	@make $(NO_PRINT) -C $(LIBFT_DIR)
	@echo "$(GREEN)Executable built: libft.a$(RESET)"

clean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Libft cleaned.$(RESET)"

fclean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)libft.a executable removed.$(RESET)"

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
