/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:20:05 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/12 11:20:07 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_player_c(t_data *data, int p_row, int p_col)
{
	mlx_texture_t		*texture;

	mlx_delete_image(data->mlx_ptr, data->p_image);
	texture = mlx_load_png("./textures/player_c.png");
	if (!texture)
		return (error(data, 'P'));
	data->p_image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!data->p_image)
		return (error(data, 'P'));
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx_ptr, data->p_image,
		(p_col * 64), (p_row * 64));
}

void	init_enemy_image(t_data *data, int x_row, int x_col)
{
	mlx_texture_t		*texture;

	mlx_delete_image(data->mlx_ptr, data->x_image);
	texture = mlx_load_png("./textures/enemy.png");
	if (!texture)
		return (error(data, 'P'));
	data->x_image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!data->x_image)
		return (error(data, 'P'));
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx_ptr, data->x_image,
		(data->x_col * 64), (data->x_row * 64));
	data->x_row = x_row;
	data->x_col = x_col;
}
