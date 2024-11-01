/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:00:54 by ctommasi          #+#    #+#             */
/*   Updated: 2024/11/01 12:00:57 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>

# define BACKGROUND "../so_long_git/textures/background.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	void	*img;
	int	img_h;
	int	img_w;
}	t_data;

int		main(void);
int		on_destroy(t_data *data);
int		on_keypress(int keysym, t_data *data);
int		render_background(t_data *data);
void	hook_and_loop(t_data data);
void	free_data(t_data *data);

#endif
