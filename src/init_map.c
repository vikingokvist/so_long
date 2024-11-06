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
	while (i < data->rows)
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

static int	assign_to_map(t_data *data, char *line, int *i)
{
	int	j;

	data->map[*i] = malloc(sizeof(char) * data->columns);
	if (!data->map[*i])
		return (1);
	j = 0;
	while (j < data->columns)
	{
		if (line[j] == '0' || line[j] == '1' || line[j] == 'C'
			|| line[j] == 'E' || line[j] == 'P')
		{
			data->map[*i][j] = line[j];
			if (line[j] == 'P')
			{
				data->player_row = *i;
				data->player_col = j;
			}
		}
		else
			return (1);
		j++;
	}
	return (0);
}

static int	read_map(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free_map(line, &fd), check_error('O'), 0);
	data->map = malloc(sizeof(char *) * data->rows);
	if (!data->map)
		return (free_map(line, &fd), 1);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (assign_to_map(data, line, &i))
			return (free_map(line, &fd), 1);
		i++;
	}
	return (close(fd), free(line), 0);
}

void	init_map(t_data *data, char **argv)
{
	if (read_map(data, argv))
	{
		check_error('I');
		if (data)
			free(data);
	}
	if (check_map_walls(data))
	{
		check_error('W');
		if (data)
			free(data);
	}
}
