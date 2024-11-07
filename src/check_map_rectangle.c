/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:19:12 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/06 16:19:15 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	free_all(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

static int	check_len(t_data *data, char *line)
{
	int		temp;
	char	**line_split;

	line_split = ft_split(line, '\n');
	temp = ft_strlen(*line_split);
	if (temp != data->columns)
		return (free_all(line_split), 1);
	return (free_all(line_split), 0);
}

void	check_map_rectangle(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*line;
	char	**array;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data, 'O');
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		array = ft_split(line, '\n');
		if (i == 0)
			data->columns = ft_strlen(*array);
		free_all(array);
		if (i != 0 && check_len(data, line))
			return (free_fd(line, &fd), error(data, 'D'));
		free(line);
		i++;
	}
	data->rows = i;
	free_fd(line, &fd);
}
