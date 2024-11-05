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

static int	get_dimensions(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("./maps/map1.ber", O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			data->columns = ft_strlen(line) - 1;
		i++;
	}
	close(fd);
	data->rows = i;
	return (0);
}

static void	free_map(t_data *data, char *line, int *fd)
{
	if (line)
		free(line);
	if (*fd >= 0)
		close(*fd);
	free_data(data);
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

int	init_map(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	line = NULL;
	fd = open("./maps/map1.ber", O_RDONLY);
	if (fd < 0 || get_dimensions(data) == -1)
		return (free_map(data, line, &fd), 1);
	data->map = malloc(sizeof(char *) * data->rows);
	if (!data->map)
		return (free_map(data, line, &fd), 1);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (assign_to_map(data, line, &i))
			return (free_map(data, line, &fd), 1);
		i++;
	}
	return (close(fd), free(line), 0);
}
