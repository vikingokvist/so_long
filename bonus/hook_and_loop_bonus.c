/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:03:26 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 18:03:27 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hook_and_loop_b(t_data *data)
{
	render_background_b(data);
	render_player_c(data, data->p_row, data->p_col);
	enemy_movement(data, 0);
	mlx_loop_hook(data->mlx_ptr, death_timer_call, data);
	mlx_key_hook(data->mlx_ptr, on_keypress_b, data);
	mlx_loop(data->mlx_ptr);
}
