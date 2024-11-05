/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:11:36 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 12:11:37 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	on_keypress(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			free_data(data);
			exit(0);
		}
		// if (keydata.key == MLX_KEY_W)
		// {
		// 	exit(0);
		// }
		// if (keydata.key == MLX_KEY_S)
		// {

		// }
		// if (keydata.key == MLX_KEY_A)
		// {

		// }
		// if (keydata.key == MLX_KEY_D)
		// {

		// }
	}
	
	
}
