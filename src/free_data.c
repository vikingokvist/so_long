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
		mlx_delete_image(data->mlx_ptr, data->img);
		data->img = NULL;
	}
	if (data->mlx_ptr)
	{
		mlx_terminate(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}
