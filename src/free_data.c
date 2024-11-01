/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:39:56 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 16:39:57 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_data(t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		data->img = NULL;
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx_ptr, data->window);
		data->window = NULL;
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
}
