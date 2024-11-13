/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_movement_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:10:49 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/13 13:10:50 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*get_textures(int i, t_data *data)
{
	char	*texture;

	texture = NULL;
	if (data->p_stance == 'w')
		texture = textures_w(i);
	else if (data->p_stance == 'a')
		texture = textures_a(i);
	else if (data->p_stance == 's')
		texture = textures_s(i);
	else if (data->p_stance == 'd')
		texture = textures_d(i);
	else if (data->p_stance == 'c')
		texture = textures_c(i);
	else if (data->p_stance == 'x')
		texture = textures_x(i);
	else
		texture = textures_r(i);
	return (texture);
}

void	render_player_movement(void *param)
{
	static int		fps;
	static int		i;
	t_data			*data;
	mlx_texture_t	*texture;

	data = (t_data *)param;
	if (data->p_img)
		mlx_delete_image(data->mlx_ptr, data->p_img);
	if (fps % 15 == 0)
		i = (i + 1) % 4;
	texture = mlx_load_png(get_textures(i, data));
	if (!texture)
		error(data, 'r');
	data->p_img = mlx_texture_to_image(data->mlx_ptr, texture);
	if (!data->p_img)
		error(data, 'r');
	mlx_image_to_window(data->mlx_ptr, data->p_img,
		data->p_col * 64, data->p_row * 64);
	mlx_delete_texture(texture);
	fps = (fps + 1) % 60;
}
