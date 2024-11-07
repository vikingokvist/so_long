/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:48:37 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/04 16:48:38 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows - 1)
	{
		if (i == 0 || i == data->rows - 1)
		{
			j = 0;
			while (j < data->columns)
			{
				if (data->map[i][j] != '1')
					return (1);
				j++;
			}
		}
		else
		{
			if (data->map[i][0] != '1'
				|| data->map[i][data->columns - 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	read_map(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	char	*temp;

	data->pre_map = ft_strdup("");
	if (!data->pre_map)
		return (free_data(data), check_error('M'), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(data->pre_map), free_data(data), check_error('O'), 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(data->pre_map, line);
		free(data->pre_map);
		data->pre_map = temp;
		free(line);
		line = get_next_line(fd);
	}
	data->map = ft_split(data->pre_map, '\n');
	close(fd);
	return (0);
}

void	init_map(t_data *data, char **argv)
{
	if (read_map(data, argv))
	{
		if (data)
			free_data(data);
		check_error('I');
	}
	if (check_map_walls(data))
	{
		if (data)
			free(data);
		check_error('W');
	}
}
