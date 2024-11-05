/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
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
		texture = mlx_load_png("./textures/collectible.png");
	else if (c == 'E')
		texture = mlx_load_png("./textures/map_exit.png");
	else if (c == 'P')
		texture = mlx_load_png("./textures/starting_pos.png");
	return (texture);
}

static mlx_image_t	*get_image(t_data *data, char c)
{
	mlx_image_t		*image;
	mlx_texture_t		*texture;

	texture = get_texture(c);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(data->mlx_ptr, texture);
	mlx_delete_texture(texture);
	if (!image)
		return (NULL);
	return (image);
}

int	render_background(t_data *data)
{
	int		x;
	int		y;
	mlx_image_t	*image;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->columns)
		{
			image = get_image(data, data->map[y][x]);
			if (!image)
				return (free_data(data), 1);
			mlx_image_to_window(data->mlx_ptr, image, x * 64 + 1, y *  64);
			x++;
		}
		y++;
	}
	return (0);
}
/*
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png("./textures/texture1.png");
	if (!texture)
		return (free_data(data), 1);
	image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!image)
		return (free_data(data), 1);
	mlx_image_to_window(data->mlx_ptr, image, 0, 0);
	return (0);
*/