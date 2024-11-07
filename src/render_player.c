/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:22:13 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/05 17:22:16 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_to_window(t_data *data, int p_row, int p_col)
{
	mlx_texture_t		*texture;

	mlx_delete_image(data->mlx_ptr, data->p_image);
	texture = mlx_load_png("./textures/player.png");
	if (!texture)
		return (check_error('P'), 1);
	data->p_image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!data->p_image)
		return (check_error('P'), 1);
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx_ptr, data->p_image,
		(p_col * 64), (p_row * 64));
	return (0);
}

static int	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->map[i][j] == 'P')
			{
				data->p_row = i;
				data->p_col = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	render_player(t_data *data)
{
	if (get_player_pos(data))
	{
		if (data)
			free_data(data);
		check_error('P');
	}
}
