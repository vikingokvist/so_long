/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:25:09 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/11 16:25:10 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_moves(t_data *data)
{
	char			*moves;
	mlx_texture_t	*texture;

	moves = ft_itoa(data->moves);
	texture = mlx_load_png("./textures/wall.png");
	if (!texture)
		error(data, 'r');
	data->moves_img = mlx_texture_to_image(data->mlx_ptr, texture);
	mlx_delete_texture(texture);
	if (!data->moves_img)
		error(data, 'r');
	mlx_image_to_window(data->mlx_ptr, data->moves_img, 0, 0);
	mlx_put_string(data->mlx_ptr, "MOVES: ", 4, 8);
	mlx_put_string(data->mlx_ptr, moves, 16, 32);
	free(moves);
}
