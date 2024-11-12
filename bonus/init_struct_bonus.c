/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:48:33 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/08 13:48:35 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_struct(t_data *data)
{
	data->mlx_ptr = NULL;
	data->img = NULL;
	data->window_name = "so_long";
	data->window_w = 0;
	data->window_h = 0;
	data->image_w = 0;
	data->image_h = 0;
	data->pre_map = NULL;
	data->map = NULL;
	data->rows = 0;
	data->columns = 0;
	data->p_pos = NULL;
	data->p_row = 0;
	data->p_col = 0;
	data->p_image = NULL;
	data->moves = 1;
	data->visited = NULL;
	data->n_collectibles = 0;
	data->found_collectibles = 0;
	data->found_exit = 0;
	data->start_row = 0;
	data->start_col = 0;
	data->death_img = NULL;
	data->show_death = false;
	data->death_timer = 0;
	data->exit = false;
	data->e_col = 0;
	data->e_row = 0;
}
