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

static void	free_data_2(t_data *data)
{
	int	i;

	if (data->visited)
	{
		i = 0;
		while (i < data->rows)
		{
			if (data->visited[i])
				free(data->visited[i]);
			i++;
		}
		free(data->visited);
	}
}

static void	free_data_1(t_data *data)
{
	int	i;

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
	if (data->p_pos)
	{
		i = 0;
		while (i < data->rows)
		{
			if (data->p_pos[i])
				free(data->p_pos[i]);
			i++;
		}
		free(data->p_pos);
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_data_1(data);
	free_data_2(data);
	if (data->pre_map)
		free(data->pre_map);
	if (data->img)
		mlx_delete_image(data->mlx_ptr, data->img);
	if (data->p_image)
		mlx_delete_image(data->mlx_ptr, data->p_image);
	if (data->mlx_ptr)
		mlx_terminate(data->mlx_ptr);
	init_struct(data);
	exit(1);
}

void	error(t_data *data, char c)
{
	if (c == 'A')
		perror("Error\nWrong amount of arguments.\nUsage: ./so_long *.ber");
	else if (c == 'B')
		perror("Error\nIncorrect .ber file extension.\n");
	else if (c == 'D')
		perror("Error\nIncorrect map dimensions.\n");
	else if (c == 'W')
		perror("Error\nMap not surrounded by walls.\n");
	else if (c == 'O')
		perror("Error\nOpening file.\n");
	else if (c == 'M')
		perror("Error\nMalloc.\n");
	else if (c == 'I')
		perror("Error\nInitialising map.\n");
	else if (c == 'w')
		perror("Error\nInitialising window.\n");
	else if (c == 'r')
		perror("Error\nRendering.\n");
	else if (c == 'P')
		perror("Error\nGetting player position.\n");
	else if (c == 'd')
		perror("Error\nMap needs 1 start/exit and at least 1 collectible.\n");
	else if (c == 'S')
		perror("Error\nMap not doable.\n");
	free_data(data);
}

void	free_fd(char *line, int *fd)
{
	if (line)
		free(line);
	if (fd && *fd >= 0)
		close(*fd);
}
