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

typedef struct s_data
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*img;
	char		*window_name;
	int			window_w;
	int			window_h;
	int			image_w;
	int			image_h;
	char		*pre_map;
	char		**map;
	int			rows;
	int			columns;
	char		**p_pos;
	int			p_row;
	int			p_col;
	mlx_image_t		*p_image;
	int			moves;
}	t_data;

int		main(int argc, char **argv);
void		init_window(t_data *data);
void		render_background(t_data *data);
void	check_valid_map(t_data *data, char **argv);
void	init_map(t_data *data, char **argv);
void	render_player(t_data *data);
int	render_to_window(t_data *data, int p_row, int p_col);
void	free_map(char *line, int *fd);
void	free_data(t_data *data);
void	check_error(char c);
void	on_keypress(struct mlx_key_data keydata, void *param);
void	hook_and_loop(t_data *data);
void	on_destroy(void *data);

#endif
