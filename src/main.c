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
		error(&data, 'A');
	init_struct(&data);
	check_ber_file(&data, argv);
	check_map_rectangle(&data, argv);
	read_map(&data, argv);
	check_walls(&data);
	check_map_dupes(&data);
	get_player_pos(&data);
	check_map_doable(&data);
	init_window(&data);
	render_background(&data);
	hook_and_loop(&data);
	error(&data, '!');
	return (0);
}
