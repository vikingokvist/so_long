/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:00:54 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 12:00:57 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_data
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
	char		*window_name;
	int			window_w;
	int			window_h;
	int			image_w;
	int			image_h;
	int			rows;
	int			columns;
	int			p_row;
	int			p_col;
	int			p_row_s;
	int			p_col_s;
	int			start_row;
	int			start_col;
	int			n_collectibles;
	int			found_collectibles;
	int			found_exit;
	int			e_row;
	int			e_col;
	int			x_row;
	int			x_col;
	int			moves;
	int			**visited;
	char		p_stance;
	char		*pre_map;
	char		**map;
	char		**map_cpy;
	char		**p_pos;
	mlx_image_t	*x_image;
	mlx_image_t	*p_img;
	mlx_image_t	*p_image;
	mlx_image_t	*moves_img;
	mlx_image_t	*death_img;
	uint64_t	death_timer;
	bool		show_death;
	bool		exit;
	int			death_amount;
}	t_data;

int		main(int argc, char **argv);
void	error(t_data *data, char c);
void	free_data(t_data *data);
void	free_fd(char *line, int *fd);
void	init_struct(t_data *data);
void	check_ber_file(t_data *data, char **argv);
void	check_map_rectangle(t_data *data, char **argv);
void	read_map(t_data *data, char **argv);
void	check_walls(t_data *data);
void	check_map_dupes(t_data *data);
void	check_map_doable(t_data *data);
void	init_window(t_data *data);
void	render_background(t_data *data);
void	get_player_pos(t_data *data);
void	render_player(t_data *data, int p_row, int p_col);
void	on_keypress(struct mlx_key_data keydata, void *param);
void	hook_and_loop(t_data *data);
void	on_keypress_b(struct mlx_key_data keydata, void *param);
void	hook_and_loop_b(t_data *data);
void	render_background_b(t_data *data);
void	death_message(t_data *data);
void	death_timer_call(void *param);
void	check_map_doable_b(t_data *data);
void	get_exit_pos(t_data *data);
void	render_moves(t_data *data);
void	get_enemy_pos(t_data *data);
void	render_player_movement(void *param);
char	*textures_w(int i);
char	*textures_a(int i);
char	*textures_s(int i);
char	*textures_d(int i);
char	*textures_c(int i);
char	*textures_r(int i);
char	*textures_x(int i);
void	render_single(t_data *data, char c);

#endif
