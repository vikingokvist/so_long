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

static void	on_keypress2(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_A && data->map[data->p_row][data->p_col - 1] != '1'
		&& keydata.action == MLX_PRESS)
	{
		data->p_col -= 1;
		data->moves++;
	}
	else if (keydata.key == MLX_KEY_D && data->map[data->p_row][data->p_col + 1] != '1'
		&& keydata.action == MLX_PRESS)
	{
		data->p_col += 1;
		data->moves++;
	}
}

void	on_keypress(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	on_keypress2(keydata, param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_data(data);
		exit(0);
	}
	else if (keydata.key == MLX_KEY_W && data->map[data->p_row - 1][data->p_col] != '1'
		&& keydata.action == MLX_PRESS)
	{
		data->p_row -= 1;
		data->moves++;
	}	
	else if (keydata.key == MLX_KEY_S && data->map[data->p_row + 1][data->p_col] != '1'
		&& keydata.action == MLX_PRESS)
	{
		data->p_row += 1;
		data->moves++;
	}
	render_player(data, data->p_row, data->p_col);
	ft_printf("MOVES = %d\n", data->moves);
}
