/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_timer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:43:12 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/11 15:43:14 by ctommasi         ###   ########.fr       */
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
		}
	}
}
