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
	data->img = mlx_xpm_file_to_image(data->mlx_ptr, BACKGROUND, &data->img_w, &data->img_h);
	if (!data->img)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img, 0, 0);
	return (0);
}
