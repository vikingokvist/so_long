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

int	init_window(t_data *data)
{
	data->window_w = 1600;
	data->window_h = 600;
	data->window_name = "so_long";
	data->mlx_ptr = mlx_init(
		data->window_w,
		data->window_h,
		data->window_name,
		true);
	if (!data->mlx_ptr)
		return (1);
	data->img = NULL;
	return (0);
}
