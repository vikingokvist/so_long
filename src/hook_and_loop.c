/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_and_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:03:26 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 18:03:27 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	hook_and_loop(t_data *data)
{
	mlx_key_hook(data->mlx_ptr, on_keypress, data);
	mlx_loop(data->mlx_ptr);
}
