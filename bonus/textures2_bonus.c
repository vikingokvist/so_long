/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:13 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/13 13:08:15 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*textures_c(int i)
{
	char	*texture;

	texture = NULL;
	if (i == 0)
		texture = "./textures/player_c1.png";
	else if (i == 1)
		texture = "./textures/player_c2.png";
	else if (i == 2)
		texture = "./textures/player_c3.png";
	else if (i == 3)
		texture = "./textures/player_c4.png";
	return (texture);
}

char	*textures_r(int i)
{
	char	*texture;

	texture = NULL;
	if (i == 0)
		texture = "./textures/player_1.png";
	else if (i == 1)
		texture = "./textures/player_2.png";
	else if (i == 2)
		texture = "./textures/player_3.png";
	else if (i == 3)
		texture = "./textures/player_4.png";
	return (texture);
}

char	*textures_x(int i)
{
	char	*texture;

	texture = NULL;
	if (i == 0)
		texture = "./textures/player_x1.png";
	else if (i == 1)
		texture = "./textures/player_x2.png";
	else if (i == 2)
		texture = "./textures/player_x3.png";
	else if (i == 3)
		texture = "./textures/player_x4.png";
	return (texture);
}
