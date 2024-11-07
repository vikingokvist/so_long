/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:39:56 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 16:39:57 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->pre_map)
		free(data->pre_map);
	if (data->map)
	{
		i = 0;
		while (i < data->rows)
		{
			if (data->map[i])
				free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	if (data->img)
		mlx_delete_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr)
	{
		mlx_terminate(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

void	free_map(char *line, int *fd)
{
	if (line)
		free(line);
	if (fd && *fd >= 0)
		close(*fd);
}

void	check_error(char c)
{
	perror("Error\n");
	if (c == 'B')
		perror("Incorrect .ber file extension\n");
	else if (c == 'R')
		perror("Incorrect map dimensions\n");
	else if (c == 'W')
		perror("Map not surrounded by walls\n");
	else if (c == 'O')
		perror("Opening file\n");
	else if (c == 'I')
		perror("Initialising map\n");
	else if (c == 'w')
		perror("Initialising window\n");
	else if (c == 'r')
		perror("Rendering background\n");
	exit(1);
}
