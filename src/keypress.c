/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:11:36 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 12:11:37 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	on_keypress1(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& data->map[data->p_row - 1][data->p_col] != '1')
	{
		data->p_row -= 1;
		ft_printf("MOVES = %d\n", data->moves++);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& data->map[data->p_row][data->p_col - 1] != '1')
	{
		data->p_col -= 1;
		ft_printf("MOVES = %d\n", data->moves++);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& data->map[data->p_row][data->p_col + 1] != '1')
	{
		data->p_col += 1;
		ft_printf("MOVES = %d\n", data->moves++);
	}
}

void	on_keypress(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	on_keypress1(keydata, param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& data->map[data->p_row + 1][data->p_col] != '1')
	{
		data->p_row += 1;
		ft_printf("MOVES = %d\n", data->moves++);
	}
	if (data->map[data->p_row][data->p_col] == 'C')
	{
		data->map[data->p_row][data->p_col] = '0';
		data->found_collectibles++;
		render_background(data);
	}
	if ((keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		|| (data->map[data->p_row][data->p_col] == 'E'
		&& data->found_collectibles == data->n_collectibles))
		error(data, '!');
	render_player(data, data->p_row, data->p_col);
}
