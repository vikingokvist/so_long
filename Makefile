# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 11:45:04 by ctommasi          #+#    #+#              #
#    Updated: 2024/11/01 11:45:07 by ctommasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
RM = rm -f

INCLUDE_DIR = -I/usr/include -Iminilibx-linux -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIB_DIR = minilibx-linux
MINILIB = $(MINILIB_DIR)/libmlx.a

SRCS_SRC = src/main.c src/keypress.c src/destroy.c
OBJS_SRC = $(SRCS_SRC:.c=.o)

ORANGE = \033[38;5;214m
GREEN = \033[38;5;82m
RESET = \033[0m

#----------------------------------------------------------------------
#			   SO_LONG
#----------------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT) $(MINILIB)
	@echo "$(ORANGE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SRC) $(MLX_FLAGS) $(LIBFT)
	@echo "$(GREEN)Executable built: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

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
	@make --no-print-directory -C $(LIBFT_DIR)

clean_libft:
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Libft cleaned.$(RESET)"

fclean_libft:
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Libft executable removed.$(RESET)"

#----------------------------------------------------------------------
#			     MINILIB
#----------------------------------------------------------------------
minilib: $(MINILIB)

$(MINILIB):
	@echo "$(ORANGE)Building minilibx...$(RESET)"
	@make --no-print-directory -C minilibx-linux

clean_minilib:
	@make --no-print-directory -C minilibx-linux clean || true
	@echo "$(GREEN)Minilibx cleaned.$(RESET)"

fclean_minilib:
	@make --no-print-directory -C minilibx-linux clean || true
	@echo "$(GREEN)Minilibx executable removed.$(RESET)"

#----------------------------------------------------------------------
#----------------------------------------------------------------------

$(NAME): $(LIBFT) $(MINILIB)

re: fclean all

.PHONY: all clean fclean libft clean_libft fclean_libft \
	minilib clean_minilib fclean_minilib