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

int	render_background(t_data *data)
{
	mlx_texture_t	*texture;
	mlx_image_t	*image;

	texture = mlx_load_png("./textures/background1.png");
	if (!texture)
		return (free_data(data), 1);
	image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!image)
		return (free_data(data), 1);
	mlx_image_to_window(data->mlx_ptr, image, 0, 0);
	return (0);
}
