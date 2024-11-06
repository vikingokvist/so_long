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

static int	check_len(t_data *data, char *line)
{
	int	temp;

	temp = ft_strlen(*ft_split(line, '\n'));
	if (temp != data->columns)
		return (1);
	return (0);
}

static int	check_map_rectangle(t_data *data, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (check_error('O'), 0);
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i == 0)
			data->columns = ft_strlen(*ft_split(line, '\n'));
		if (i != 0 && check_len(data, line))
			return (free_map(line, &fd), 1);
		free(line);
		i++;
	}
	data->rows = i;
	return (free_map(line, &fd), 0);
}

static int	check_ber_file(char **argv)
{
	char	*filename;
	char	*extension;
	int		len_file;
	int		len_extension;

	filename = argv[1];
	extension = ".ber";
	len_file = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_file < len_extension)
		return (1);
	if (ft_strcmp(&filename[len_file - len_extension], extension) == 0)
		return (0);
	return (1);
}

void	check_valid_map(t_data *data, char **argv)
{
	if (check_ber_file(argv))
	{
		check_error('B');
		if (data)
			free_data(data);
	}
	else if (check_map_rectangle(data, argv))
	{
		check_error('R');
		if (data)
			free_data(data);
	}
}
