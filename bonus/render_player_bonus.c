/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:29:05 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/11 13:29:07 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_player(t_data *data, int p_row, int p_col)
{
	mlx_texture_t		*texture;

	mlx_delete_image(data->mlx_ptr, data->p_image);
	texture = mlx_load_png("./textures/player.png");
	if (!texture)
		return (error(data, 'P'));
	data->p_image = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!data->p_image)
		return (error(data, 'P'));
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx_ptr, data->p_image,
		(p_col * 64), (p_row * 64));
}
