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

int	init_map(t_data *data)
{
	int	i;
	int	fd;
	char	*line;

	i = 0;
	fd = open("./maps/map1.ber", O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < 5)
	{
		line = get_next_line(fd);
		j = 0;
		while (j < strlen(line))
		{
			if (line[j] != '0' || line[j] != '1' || line[j] != 'C'
				|| line[j] != 'E' || line[j] != 'P')
				return (1);
			data.map[i][j] = line[j];
			j++;
		}
		i++;	
	}
	return (0);
}