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

void	read_map(t_data *data, char **argv)
{
	int		fd;
	char	*line;
	char	*temp;

	data->pre_map = ft_strdup("");
	if (!data->pre_map)
		return (error(data, 'M'));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data, 'O');
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
}

