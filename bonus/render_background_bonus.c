/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:57:42 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 17:57:43 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static mlx_texture_t	*get_texture(char c)
{
	mlx_texture_t		*texture;

	texture = NULL;
	if (c == '0')
		texture = mlx_load_png("./textures/empty_space.png");
	else if (c == '1')
		texture = mlx_load_png("./textures/wall.png");
	else if (c == 'C')
		texture = mlx_load_png("./textures/collectible_ladder.png");
	else if (c == 'E')
		texture = mlx_load_png("./textures/exit_0.png");
	else if (c == 'P')
		texture = mlx_load_png("./textures/starting_pos.png");
	else if (c == 'e')
		texture = mlx_load_png("./textures/exit_1.png");
	return (texture);
}

static mlx_image_t	*get_image(t_data *data, char c)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = get_texture(c);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(data->mlx_ptr, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (NULL);
	return (image);
}

void	render_background_b(t_data *data)
{
	int			x;
	int			y;
	mlx_image_t	*image;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			image = get_image(data, data->map[y][x]);
			if (!image)
				error(data, 'r');
			mlx_image_to_window(data->mlx_ptr, image, (x * 64), y * 64);
			x++;
		}
		y++;
	}
}
