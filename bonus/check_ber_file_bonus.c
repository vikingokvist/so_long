/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:01:59 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/08 14:02:01 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_ber_file(t_data *data, char **argv)
{
	char	*filename;
	char	*extension;
	int		len_file;
	int		len_extension;

	filename = argv[1];
	extension = ".ber";
	len_file = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_file < len_extension)
		error(data, 'B');
	if (ft_strcmp(&filename[len_file - len_extension], extension) != 0)
		error(data, 'B');
}
