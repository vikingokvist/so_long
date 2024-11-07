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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (1);
	data.moves = 0;
	check_valid_map(&data, argv);
	init_map(&data, argv);
	init_window(&data);
	render_background(&data);
	render_player(&data);
	hook_and_loop(&data);
	free_data(&data);
	return (0);
}
