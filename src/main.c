/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:05:56 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/31 17:05:58 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window = mlx_new_window(data.mlx_ptr, 1024, 768, "so_long");
	if (!data.window)
		return (free(data.mlx_ptr), 1);
	if (render_background(&data))
		return (free_data(&data), 1);
	hook_and_loop(data);
	return (free_data(&data), 0);
}
