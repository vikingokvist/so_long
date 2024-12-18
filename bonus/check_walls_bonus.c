/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:49:11 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/08 13:49:12 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		if (i == 0 || i == data->rows - 1)
		{
			j = 0;
			while (j < data->columns)
			{
				if (data->map[i][j] != '1')
					return (error(data, 'W'));
				j++;
			}
		}
		else
		{
			if (data->map[i][0] != '1'
				|| data->map[i][data->columns - 1] != '1')
				return (error(data, 'W'));
		}
		i++;
	}
}
