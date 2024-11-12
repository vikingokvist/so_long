/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:22:13 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/05 17:22:16 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_row_s = i;
				data->p_col_s = j;
				data->p_row = i;
				data->p_col = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_exit_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'E')
			{
				data->e_row = i;
				data->e_col = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_enemy_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'X')
			{
				data->x_row = i;
				data->x_col = j;
				break ;
			}
			j++;
		}
		i++;
	}
}