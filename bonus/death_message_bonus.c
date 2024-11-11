/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:38:37 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/11 14:38:38 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	death_message(t_data *data)
{
	mlx_texture_t	*texture;

	data->p_row = data->p_row_s;
	data->p_col = data->p_col_s;
	texture = mlx_load_png("./textures/death_msg.png");
	data->death_img = mlx_texture_to_image(data->mlx_ptr, texture);
	mlx_image_to_window(data->mlx_ptr, data->death_img,
		data->window_w / 2 - 600, data->window_h / 2 - 75);
	mlx_delete_texture(texture);
	data->death_timer = mlx_get_time();
	data->show_death = true;
}
