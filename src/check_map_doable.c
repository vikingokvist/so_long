/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_doable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:26:28 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/08 11:26:29 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_move(t_data *data, int s_row, int s_col)
{
	if (s_row > 0 && s_row < data->rows && s_col > 0
		&& s_col < data->columns && data->map[s_row][s_col] != '1'
		&& !data->visited[s_row][s_col])
		return (1);
	return (0);
}

static void	dfs(t_data *data, int s_row, int s_col)
{
	if (!is_valid_move(data, s_row, s_col))
		return ;
	data->visited[s_row][s_col] = 1;
	if (data->map[s_row][s_col] == 'C')
		data->found_collectibles++;
	if (data->map[s_row][s_col] == 'E')
		data->found_exit++;
	dfs(data, s_row + 1, s_col);
	dfs(data, s_row - 1, s_col);
	dfs(data, s_row, s_col + 1);
	dfs(data, s_row, s_col - 1);
}

void	check_map_doable(t_data *data)
{
	int	i;

	data->visited = malloc(sizeof(int *) * data->rows);
	if (!data->visited)
		error(data, 'M');
	i = 0;
	while (i < data->rows)
	{
		data->visited[i] = ft_calloc(data->columns, sizeof(int));
		i++;
	}
	data->start_row = data->p_row;
	data->start_col = data->p_col;
	dfs(data, data->start_row, data->start_col);
	if (data->found_collectibles != data->n_collectibles)
		error(data, 'S');
	if (!data->found_exit)
		error(data, 'S');
	data->found_collectibles = 0;
}
