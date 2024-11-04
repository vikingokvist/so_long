/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
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
	data->mlx_ptr = mlx_init(800, 600, "so_long", true);
	if (!data->mlx_ptr)
		return (ft_printf("failed to initialise MLX"), 1);
	data->img = NULL;
	return (0);
}

