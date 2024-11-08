/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_dupes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:06:26 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/08 14:06:27 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_dupe(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'C')
				data->n_collectibles++;
			if (data->map[i][j] == 'P' || data->map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 2)
		error(data, 'd');
}
