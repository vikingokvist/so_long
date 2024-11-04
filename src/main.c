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
	
	if (init_window(&data))
		return (1);
	if (render_background(&data))
		return (1);
	hook_and_loop(&data);
	return (free_data(&data), 0);
}
