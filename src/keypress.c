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
	ft_printf("Pressed Key: %c\n", keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_data(data);
		mlx_terminate(data->mlx_ptr);
		exit(0);
	}
}
