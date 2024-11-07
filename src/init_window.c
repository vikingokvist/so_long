/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:25:07 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/04 10:25:09 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_data *data)
{
	data->window_w = data->columns * 64;
	data->window_h = data->rows * 64;
	data->window_name = "so_long";
	data->mlx_ptr = mlx_init(data->window_w, data->window_h,
			data->window_name, false);
	if (!data->mlx_ptr)
	{
		free_data(data);
		check_error('w');
	}
	data->img = NULL;
}
