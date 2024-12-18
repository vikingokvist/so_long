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

static void	init_struct2(t_data *data)
{
	data->window_w = 0;
	data->window_h = 0;
	data->image_w = 0;
	data->image_h = 0;
	data->p_row = 0;
	data->p_col = 0;
	data->rows = 0;
	data->columns = 0;
	data->e_col = 0;
	data->e_row = 0;
	data->p_row_s = 0;
	data->p_col_s = 0;
	data->moves = 0;
	data->n_collectibles = 0;
	data->found_collectibles = 0;
	data->found_exit = 0;
	data->start_row = 0;
	data->start_col = 0;
	data->death_timer = 0;
	data->x_row = 0;
	data->x_col = 0;
}

void	init_struct(t_data *data)
{
	init_struct2(data);
	data->mlx_ptr = NULL;
	data->img = NULL;
	data->pre_map = NULL;
	data->map = NULL;
	data->map_cpy = NULL;
	data->p_pos = NULL;
	data->p_image = NULL;
	data->visited = NULL;
	data->death_img = NULL;
	data->moves_img = NULL;
	data->x_image = NULL;
	data->show_death = false;
	data->exit = false;
	data->window_name = "so_long";
	data->p_stance = 'r';
	data->death_amount = 0;
	data->show_death = false;
}
