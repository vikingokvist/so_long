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

# define BACKGROUND_IMAGE "../so_long_git/textures/background.xpm"
# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define WINDOW_TITLE "so_long"

typedef struct s_data
{
	mlx_t	*mlx_ptr;
	mlx_image_t	*img;
	char	*window_name;
	int	window_w;
	int	window_h;
	int	image_w;
	int	image_h;
	char	**map;
	int	rows;
	int	columns;
	char	**player_pos;
	int	player_row;
	int	player_col;
}	t_data;

int		main(void);
int		init_window(t_data *data);
int		init_map(t_data *data);
int	render_background(t_data *data);
void	on_keypress(struct mlx_key_data keydata, void *param);
void	hook_and_loop(t_data *data);
void	free_data(t_data *data);
void	on_destroy(void *data);


#endif
