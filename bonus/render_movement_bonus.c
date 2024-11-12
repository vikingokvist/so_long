/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:36 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/12 18:19:38 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*get_image_a(int i)
{
	char	*filepath;

	filepath = NULL;
	if (i == 0)
		filepath = "./textures/player_a1.png";
	else if (i == 1)
		filepath = "./textures/player_a2.png";
	else if (i == 2)
		filepath = "./textures/player_a3.png";
	else if (i == 3)
		filepath = "./textures/player_a4.png";
	return (filepath);
}

char	*get_image_d(int i)
{
	char	*filepath;

	filepath = NULL;
	if (i == 0)
		filepath = "./textures/player_d1.png";
	else if (i == 1)
		filepath = "./textures/player_d2.png";
	else if (i == 2)
		filepath = "./textures/player_d3.png";
	else if (i == 3)
		filepath = "./textures/player_d4.png";
	return (filepath);
}

char	*get_image_w(int i)
{
	char	*filepath;

	filepath = NULL;
	if (i == 0)
		filepath = "./textures/player_w1.png";
	else if (i == 1)
		filepath = "./textures/player_w2.png";
	else if (i == 2)
		filepath = "./textures/player_w3.png";
	else if (i == 3)
		filepath = "./textures/player_w4.png";
	return (filepath);
}

char	*get_image_s(int i)
{
	char	*filepath;

	filepath = NULL;
	if (i == 0)
		filepath = "./textures/player_s1.png";
	else if (i == 1)
		filepath = "./textures/player_s2.png";
	else if (i == 2)
		filepath = "./textures/player_s3.png";
	else if (i == 3)
		filepath = "./textures/player_s4.png";
	return (filepath);
}
