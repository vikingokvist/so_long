/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:53:59 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/12 12:54:01 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	enemy_movement_s(t_data *data)
{
	data->map[data->x_row + 1][data->x_col] = 'X';
	data->map[data->x_row][data->x_col] = '0';
	init_enemy_image(data, data->x_row + 1, data->x_col);
}

static void	enemy_movement_w(t_data *data)
{
	data->map[data->x_row - 1][data->x_col] = 'X';
	data->map[data->x_row][data->x_col] = '0';
	init_enemy_image(data, data->x_row - 1, data->x_col);
}

static void	enemy_movement_d(t_data *data)
{
	data->map[data->x_row][data->x_col + 1] = 'X';
	data->map[data->x_row][data->x_col] = '0';
	init_enemy_image(data, data->x_row, data->x_col + 1);
}

static void	enemy_movement_a(t_data *data)
{
	data->map[data->x_row][data->x_col - 1] = 'X';
	data->map[data->x_row][data->x_col] = '0';
	init_enemy_image(data, data->x_row, data->x_col - 1);
}

void	enemy_movement(t_data *data, int start_stop)
{
	int	i;

	i = 0;
	if (start_stop == 1)
		return ;
	while (i < 1000)
	{
		if (data->x_row + 1 < data->rows && data->map[data->x_row + 1][data->x_col] == '0')
			enemy_movement_s(data);
		else if (data->x_col + 1 < data->columns && data->map[data->x_row][data->x_col + 1] == '0')
			enemy_movement_d(data);
		else if (data->x_row - 1 >= 0 && data->map[data->x_row - 1][data->x_col] == '0')
			enemy_movement_w(data);
		else if (data->x_col - 1 >= 0 && data->map[data->x_row][data->x_col - 1] == '0')
   			enemy_movement_a(data);
		i++;
	}
}
