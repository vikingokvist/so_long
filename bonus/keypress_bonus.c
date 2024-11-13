/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:40:12 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/11 17:40:15 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	on_keypress_moves_c(t_data *data)
{
	if (data->found_collectibles == data->n_collectibles
		&& data->exit == false)
	{
		data->map[data->e_row][data->e_col] = 'e';
		data->exit = true;
		render_background_b(data);
	}
	if (data->map[data->p_row][data->p_col] == 'C')
	{
		data->map[data->p_row][data->p_col] = '0';
		data->found_collectibles++;
		render_background_b(data);
		data->p_stance = 'c';
	}
	if (data->map[data->p_row][data->p_col] == 'X')
	{
		data->p_stance = 'x';
		death_message(data);
	}
}

static void	on_keypress_moves_d_a(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& data->map[data->p_row][data->p_col + 1] != '1')
	{
		data->p_col += 1;
		data->moves++;
		data->p_stance = 'd';
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& data->map[data->p_row][data->p_col - 1] != '1')
	{
		data->p_col -= 1;
		data->moves++;
		data->p_stance = 'a';
	}
}

static void	on_keypress_moves_w_s(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& data->map[data->p_row - 1][data->p_col] != '1')
	{
		data->p_row -= 1;
		data->moves++;
		data->p_stance = 'w';
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& data->map[data->p_row + 1][data->p_col] != '1')
	{
		data->p_row += 1;
		data->moves++;
		data->p_stance = 's';
	}
}

void	on_keypress_b(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	on_keypress_moves_d_a(keydata, param);
	on_keypress_moves_w_s(keydata, param);
	on_keypress_moves_c(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		error(data, '!');
	}
	if (data->map[data->p_row][data->p_col] == 'e'
		&& data->found_collectibles == data->n_collectibles)
	{
		data->p_stance = 'c';
		error(data, '!');
	}
	render_moves(data);
}
