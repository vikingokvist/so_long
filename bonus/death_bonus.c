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

void	death_timer_call(void *param)
{
	t_data		*data;
	uint64_t	current_time;

	data = (t_data *)param;
	if (data->show_death)
	{
		current_time = mlx_get_time();
		if (data->death_timer - current_time >= 300)
		{
			sleep(1);
			mlx_delete_image(data->mlx_ptr, data->death_img);
			data->death_img = NULL;
			data->show_death = false;
			render_player_d(data, data->p_row, data->p_col);
		}
	}
}

void	death_message(t_data *data)
{
	mlx_texture_t	*texture;
	float			width_scale;
	float			height_scale;
	float			scale_factor;

	width_scale = (data->window_w / 2) / (float)1266;
	height_scale = (data->window_h / 4) / (float)86;
	scale_factor = fmin(width_scale, height_scale);
	texture = mlx_load_png("./textures/death_msg.png");
	data->death_img = mlx_texture_to_image(data->mlx_ptr, texture);
	mlx_resize_image(data->death_img,
		(int)(1266 * scale_factor), (int)(86 * scale_factor));
	mlx_image_to_window(data->mlx_ptr, data->death_img,
		(data->window_w / 2) - ((int)(1266 * scale_factor) / 2),
		(data->window_h / 2) - ((int)(86 * scale_factor) / 2));
	mlx_delete_texture(texture);
	data->death_timer = mlx_get_time();
	data->show_death = true;
	data->p_row = data->p_row_s;
	data->p_col = data->p_col_s;
}
